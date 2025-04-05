/* Write your PL/SQL query statement below */
SELECT request_at Day, 
    ROUND(COUNT(CASE status WHEN 'completed' THEN NULL ELSE 0 END)/COUNT(*), 2) "Cancellation Rate"
FROM TRIPS
WHERE request_at BETWEEN '2013-10-01' AND '2013-10-03'
AND 'No' = ALL(SELECT banned FROM USERS WHERE users_id IN (client_id, driver_id))
GROUP BY request_at;