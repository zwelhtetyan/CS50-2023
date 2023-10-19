CREATE TABLE users (
  id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  username TEXT NOT NULL,
  hash TEXT NOT NULL,
  cash NUMERIC NOT NULL DEFAULT 10000.00
);

CREATE TABLE sqlite_sequence(
  name,seq
);

CREATE UNIQUE INDEX username
ON users (username);
