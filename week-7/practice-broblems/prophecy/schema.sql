CREATE TABLE IF NOT EXISTS students (
  id INTEGER PRIMARY KEY,
  name TEXT NOT NULL UNIQUE
);

CREATE TABLE IF NOT EXISTS houses (
  id INTEGER PRIMARY KEY,
  name TEXT NOT NULL UNIQUE,
  head TEXT NOT NULL UNIQUE
);

CREATE TABLE IF NOT EXISTS house_assignments (
  student_name INTEGER NOT NULL UNIQUE,
  house_name INTEGER NOT NULL UNIQUE,
  PRIMARY KEY(student_name, house_name),
  FOREIGN KEY(student_name) REFERENCES students(name),
  FOREIGN KEY(house_name) REFERENCES houses(name)
);