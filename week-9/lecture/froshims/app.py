from flask import Flask, render_template, request, redirect

app = Flask(__name__)

REGISTERANTS = {}

sports = ["Football", "Basketball", "Volleyball"]


@app.route("/")
def index():
    return render_template("index.html", sports=sports)


@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    sport = request.form.get("sport")
    if not name.strip() or not sport or sport not in sports:
        return render_template("failure.html")

    REGISTERANTS[name] = sport
    return redirect("/registerants")


@app.route("/registerants")
def registerants():
    return render_template("registerants.html", registerants=REGISTERANTS)
