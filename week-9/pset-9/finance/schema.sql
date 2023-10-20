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
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  timestamp DATETIME DEFAULT CURRENT_TIMESTAMP,
  user_id INTEGER,
  stock_name TEXT,
  stock_symbol TEXT,
  stock_share INTEGER,
  stock_price REAL,
  type TEXT CHECK (type IN ('buy', 'sell'))
);
