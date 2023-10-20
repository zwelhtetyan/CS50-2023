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

CREATE TABLE histories (
  id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  timestamp DATETIME DEFAULT CURRENT_TIMESTAMP NOT NULL,
  user_id INTEGER NOT NULL,
  stock_name TEXT NOT NULL,
  stock_symbol TEXT NOT NULL,
  stock_share INTEGER NOT NULL,
  stock_price REAL NOT NULL,
  type TEXT CHECK (type IN ('buy', 'sell')) NOT NULL
);

