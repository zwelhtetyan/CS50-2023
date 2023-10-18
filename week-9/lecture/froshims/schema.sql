CREATE TABLE people (
  id INTEGER PRIMARY KEY,
  name TEXT,
  sport_id INTEGER,
  FOREIGN KEY(sport_id) REFERENCES sports(id)
);


CREATE TABLE sports (
  id INTEGER PRIMARY KEY,
   name TEXT
);

