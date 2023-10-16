SELECT title
  FROM movies
  JOIN ratings
    ON ratings.movie_id = movies.id
  JOIN stars
    ON stars.movie_id = movies.id
  JOIN people
    ON people.id = stars.person_id
 WHERE people.name = 'Chadwick Boseman'
 ORDER BY ratings.rating DESC LIMIT 5;