import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session, abort, url_for

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        name = request.form.get("name").strip()
        month = request.form.get("month").strip()
        day = request.form.get("day").strip()

        if not name or not month or not day:
            return render_template("error.html")

        # TODO: Add the user's entry into the database
        db.execute(
            "INSERT INTO birthdays (name, month, day) VALUES(?, ?, ?)", name, month, day)

        return redirect("/")

    else:

        birthdays = db.execute("SELECT * FROM birthdays")

        return render_template("index.html", birthdays=birthdays)


@app.route('/people/<int:id>', methods=['GET', 'POST', 'DELETE'])
def get_people(id):
    if request.method == 'DELETE':
        people = db.execute("DELETE FROM birthdays WHERE id = ?", id)

        if not people:
            abort(404)

        return jsonify({"message": "Record deleted successfully"})

    elif request.method == 'POST':
        name = request.form.get("name").strip()
        month = request.form.get("month").strip()
        day = request.form.get("day").strip()

        if not name or not month or not day:
            return render_template("error.html")

        people = db.execute(
            "UPDATE birthdays SET name = ?, month = ?, day = ? WHERE id = ?", name, month, day, id)

        return redirect('/')

    people = db.execute("SELECT * FROM birthdays WHERE id = ?", id)

    if not len(people):
        abort(404)

    return jsonify(people)
