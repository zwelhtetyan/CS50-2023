SELECT COUNT(title) as n
  FROM movies
  JOIN ratings
    ON ratings.movie_id = movies.id
 WHERE rating = '10.0';
-- SELECT COUNT(title) as n FROM movies WHERE id IN (SELECT movie_id FROM ratings WHERE rating = '10.0');