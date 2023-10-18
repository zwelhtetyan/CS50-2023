from flask import Flask, render_template, request, redirect
from cs50 import SQL

db = SQL("sqlite:///registerants.db")

app = Flask(__name__)


@app.route("/")
def index():
    sports = db.execute("SELECT * FROM sports")
    return render_template("index.html", sports=sports)


@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    sport_id = request.form.get("sport_id")

    if not name.strip() or not sport_id:
        return render_template("failure.html")

    sport = db.execute("SELECT id FROM sports where id = ?", sport_id)
    print(sport)
    if not sport or int(sport_id) != sport[0]["id"]:
        return render_template("failure.html")

    db.execute("INSERT INTO people (name, sport_id) VALUES(?, ?)", name, sport_id)

    return redirect("/registerants")


@app.route("/registerants")
def registerants():
    registerants = db.execute(
        "SELECT people.name as name, sports.name as sport FROM people JOIN sports ON sports.id = people.sport_id")
    print(registerants)
    return render_template("registerants.html", registerants=registerants, title="Registerants")
