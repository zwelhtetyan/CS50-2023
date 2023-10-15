SELECT DISTINCT movies.title FROM movies 
JOIN stars AS s1 ON s1.movie_id = movies.id 
JOIN people AS p1 ON p1.id = s1.person_id 
JOIN stars AS s2 ON s2.movie_id = movies.id 
JOIN people AS p2 ON p2.id = s2.person_id 
WHERE (p1.name = 'Bradley Cooper' OR p2.name = 'Bradley Cooper') 
AND (p1.name = 'Jennifer Lawrence' OR p2.name = 'Jennifer Lawrence');

