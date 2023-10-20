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
    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol").strip()
        share = request.form.get("share").strip()

        if not symbol:
            return apology("must provide symbol", 401)

        if not share:
            return apology("must provide share", 401)

        if not share.isnumeric() or int(share) < 1:
            return apology("share must be positive integer")

        symbol = lookup(symbol)

        if symbol is None:
            return apology("Invalid symbol", 403)

        row_cash = db.execute(
            "SELECT cash FROM users WHERE id = ?", session.get("user_id"))

        if not len(row_cash):
            return apology("Invalid user", 403)

        total_costs = int(symbol["price"]) * int(share)
        current_cash = int(row_cash[0]["cash"])

        if current_cash < total_costs:
            return apology("can't afford", 403)

        # insert table -> todo

        return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


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
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not password:
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", username)

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], password):
            return apology("invalid username and/or password", 403)

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
            return apology("must provide symbol", 401)

        quote = lookup(symbol)

        if quote is None:
            return apology("Invalid symbol", 403)

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
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not password or not confirmation:
            return apology("must provide both password and confirmation", 403)

        elif password != confirmation:
            return apology("passwords do not match", 401)

        # Query database for username
        rows_username = db.execute(
            "SELECT username FROM users WHERE username = ?", username)

        # check user is already exists
        if len(rows_username):
            return apology("username already exists", 409)

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
    return apology("TODO")
