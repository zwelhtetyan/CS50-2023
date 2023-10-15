SELECT people.name FROM people 
JOIN stars ON stars.person_id = id 
WHERE stars.movie_id = (SELECT id FROM movies WHERE title = 'Toy Story');