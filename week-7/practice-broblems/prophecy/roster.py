import csv
from cs50 import SQL
from os import path

FILE_NAME = "students.csv"
DB_NAME = "roster.db"

if path.exists(DB_NAME):
    db = SQL("sqlite:///roster.db")
else:
    print(f"Filename {DB_NAME} doesn't exits!")


students = list()
houses = list()


def main():
    with open(FILE_NAME, 'r') as file:
        reader = csv.DictReader(file)
        for row in reader:
            students.append(row)
            house = row["house"]
            house_exits = any(item.get("house") == house for item in houses)

            if not house_exits:
                houses.append({"house": row["house"], "head": row["head"]})

    # creating table
    db.execute(
        "CREATE TABLE IF NOT EXISTS students (id INTEGER PRIMARY KEY, name TEXT NOT NULL UNIQUE)")
    db.execute(
        "CREATE TABLE IF NOT EXISTS houses (id INTEGER PRIMARY KEY, name TEXT NOT NULL UNIQUE, head TEXT NOT NULL UNIQUE)")
    db.execute("CREATE TABLE IF NOT EXISTS house_assignments (student_name TEXT NOT NULL, house_name TEXT NOT NULL, PRIMARY KEY(student_name, house_name), FOREIGN KEY(student_name) REFERENCES students(name), FOREIGN KEY(house_name) REFERENCES houses(name))")

    # inserting into table
    for house in houses:
        house_name = house["house"]
        head_name = house["head"]
        db.execute("INSERT INTO houses (name, head) VALUES(?,?)",
                   house_name, head_name)

    for student in students:
        student_name = student["student_name"]
        house_name = student["house"]
        db.execute(
            "INSERT INTO students (name) VALUES(?)", student_name)
        db.execute(
            "INSERT INTO house_assignments (student_name, house_name) VALUES(?,?)", student_name, house_name)


if __name__ == "__main__":
    main()
