import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    current_user_id = session.get("user_id")
    row_stocks = db.execute("SELECT stock_name, stock_symbol, SUM(CASE WHEN type = 'buy' THEN stock_share ELSE 0 END) - SUM(CASE WHEN type = 'sell' THEN stock_share ELSE 0 END) AS net_stock_share, stock_price FROM histories WHERE user_id = ? GROUP BY stock_name, stock_symbol HAVING net_stock_share != 0 ORDER BY timestamp DESC", current_user_id)

    # total_price = 0
    # for row in row_stocks:
    #     total_stock_price = float(row["stock_price"]) * int(row["net_stock_share"])
    #     total_price += total_stock_price

    row_cash = db.execute(
            "SELECT cash FROM users WHERE id = ?", current_user_id)

    if not len(row_cash):
            return apology("Invalid user", 400)

    current_cash = float(row_cash[0]["cash"])

    return render_template("index.html", stocks=row_stocks, current_cash=usd(current_cash))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol").strip()
        share = request.form.get("shares").strip()

        if not symbol:
            return apology("must provide symbol", 401)

        if not share:
            return apology("must provide share", 401)

        if not share.isnumeric() or int(share) < 1:
            return apology("share must be positive integer")

        stock = lookup(symbol)

        if stock is None:
            return apology("Invalid symbol", 400)

        current_user_id = session.get("user_id")

        row_cash = db.execute(
            "SELECT cash FROM users WHERE id = ?", current_user_id)

        if not len(row_cash):
            return apology("Invalid user", 400)

        total_costs = float(stock["price"]) * int(share)
        current_cash = float(row_cash[0]["cash"])

        if current_cash < total_costs:
            return apology("can't afford", 400)

        db.execute(
            "INSERT INTO histories (user_id, stock_name, stock_symbol, stock_share, stock_price, type) VALUES(?,?,?,?,?,?)", current_user_id, symbol, symbol, share, stock["price"], 'buy')

        db.execute("UPDATE users set cash = ?", current_cash - total_costs)

        # flash messing
        flash(f"Successfully bought {symbol.upper()}({share})")

        return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    current_user_id = session.get("user_id")
    rows_histories = db.execute("SELECT stock_symbol, stock_share, stock_price, timestamp, type FROM histories WHERE user_id = ? ORDER BY timestamp", current_user_id)
    return render_template("history.html", histories=rows_histories)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Get form data
        username = request.form.get("username").strip()
        password = request.form.get("password").strip()

        # Ensure username was submitted
        if not username:
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not password:
            return apology("must provide password", 400)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", username)

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], password):
            return apology("invalid username and/or password", 400)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # flash messing
        flash(f"Successfully login as {rows[0]['username']}")

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol").strip()

        if not symbol:
            return apology("must provide symbol", 400)

        quote = lookup(symbol)

        if quote is None:
            return apology("Invalid symbol", 400)

        return render_template("quoted.html", name=quote["name"], price=usd(quote["price"]), symbol=quote["symbol"])

    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Get form data
        username = request.form.get("username").strip()
        password = request.form.get("password").strip()
        confirmation = request.form.get("confirmation").strip()

        # Ensure username was submitted
        if not username:
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not password or not confirmation:
            return apology("must provide both password and confirmation", 400)

        elif password != confirmation:
            return apology("passwords do not match", 400)

        # Query database for username
        rows_username = db.execute(
            "SELECT username FROM users WHERE username = ?", username)

        # check user is already exists
        if len(rows_username):
            return apology("username already exists", 400)

        # generate hashed password
        hash = generate_password_hash(password)

        # add user into db
        db.execute(
            "INSERT INTO users (username, hash) VALUES(?, ?)", username, hash)

        # get his/her id
        row_user = db.execute(
            "SELECT id, username FROM users WHERE username = ?", username)

        session["user_id"] = row_user[0]["id"]

        # flash messing
        flash(f"Successfully registered as {row_user[0]['username']}")

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol").strip()
        share = request.form.get("shares").strip()

        if not symbol:
            return apology("must provide symbol", 401)

        if not share:
            return apology("must provide share", 401)

        if not share.isnumeric() or int(share) < 1:
            return apology("share must be positive integer")

        # row_stock_names = db.execute("SELECT DISTINCT stock_name FROM histories")
        current_user_id = session.get("user_id")
        row_stocks = db.execute("SELECT stock_symbol, SUM(CASE WHEN type = 'buy' THEN stock_share ELSE 0 END) - SUM(CASE WHEN type = 'sell' THEN stock_share ELSE 0 END) AS net_stock_share, stock_price FROM histories WHERE user_id = ? GROUP BY stock_name, stock_symbol HAVING net_stock_share != 0", current_user_id)

        valid_symbol_of_user = False
        current_stock = {}

        for stock in row_stocks:
            if stock["stock_symbol"].lower() == symbol.lower():
                valid_symbol_of_user = True
                current_stock = stock
                break

        if not valid_symbol_of_user:
            return apology(f"symbol ({symbol}) not found!", 400)

        if int(share) > current_stock["net_stock_share"]:
            return apology("too many shares", 400)

        db.execute(
            "INSERT INTO histories (user_id, stock_name, stock_symbol, stock_share, stock_price, type) VALUES(?,?,?,?,?,?)", current_user_id, symbol, symbol, share, current_stock["stock_price"], 'sell')

        row_cash = db.execute(
            "SELECT cash FROM users WHERE id = ?", current_user_id)

        if not len(row_cash):
            return apology("Invalid user", 400)

        current_cash = float(row_cash[0]["cash"])
        total_costs = float(current_stock["stock_price"]) * int(share)

        db.execute("UPDATE users set cash = ?", current_cash + total_costs)

        # flash messing
        flash(f"Successfully sold {symbol.upper()}({share})")

        return redirect("/")

    else:
        current_user_id = session.get("user_id")
        row_stock_names = db.execute("SELECT stock_symbol, SUM(CASE WHEN type = 'buy' THEN stock_share ELSE 0 END) - SUM(CASE WHEN type = 'sell' THEN stock_share ELSE 0 END) AS net_stock_share FROM histories WHERE user_id = ? GROUP BY stock_name, stock_symbol HAVING net_stock_share != 0", current_user_id)
        return render_template("sell.html", stock_names=row_stock_names)
