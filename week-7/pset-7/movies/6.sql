SELECT avg(ratings.rating) FROM movies 
JOIN ratings ON ratings.movie_id = movies.id 
WHERE movies.year = '2012';