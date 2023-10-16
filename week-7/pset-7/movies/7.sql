SELECT title, ratings.rating
  FROM movies
  JOIN ratings
    ON ratings.movie_id = id
 WHERE year = '2010'
 ORDER BY ratings.rating DESC, title;