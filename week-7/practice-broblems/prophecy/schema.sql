CREATE TABLE students (
  id INTEGER,
  student_name TEXT,
  house_id INTEGER,
  head_id INTEGER,
  PRIMARY KEY(id)
  FOREIGN KEY house_id REFERENCES houses(id)
  FOREIGN KEY head_id REFERENCES heads(id)
);

CREATE TABLE IF NOT EXISTS houses (
  id INTEGER PRIMARY KEY,
  name TEXT
);

CREATE TABLE IF NOT EXISTS heads (
  id INTEGER PRIMARY  KEY,
   name TEXT
);