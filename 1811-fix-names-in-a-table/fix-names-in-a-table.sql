# Write your MySQL query statement below
# Write your MySQL query statement below
SELECT user_id, 
CONCAT(UPPER(LEFT(name,1)) , LOWER(SUBSTR(name,2))) name 
FROM Users ORDER BY user_id;