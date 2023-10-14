from cs50 import SQL

db = SQL("sqlite:///roster.db")

# creating
db.execute("CREATE TABLE IF NOT EXISTS houses (id INTEGER PRIMARY KEY, name TEXT)")
db.execute("CREATE TABLE IF NOT EXISTS heads (id INTEGER PRIMARY  KEY, name TEXT)")


# inserting values by selecting from previous students table
db.execute("INSERT INTO houses (name) SELECT house FROM students")
db.execute("INSERT INTO heads (name) SELECT head FROM students")

# selecting
houses = db.execute("SELECT * FROM houses")
heads = db.execute("SELECT * FROM heads")

# print(houses)
# print(heads)
