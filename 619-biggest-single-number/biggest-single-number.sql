SELECT MAX(num) AS num
FROM MyNumbers
WHERE num NOT IN (
    SELECT num 
    FROM MyNumbers 
    GROUP BY num 
    HAVING COUNT(num) > 1
);


/*SELECT COALESCE((
    SELECT num
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(num) = 1
    ORDER BY num DESC
    LIMIT 1
), NULL) AS num;
*/