# Write your MySQL query statement below
SELECT *
FROM Patients
WHERE conditions LIKE 'DIAB1%'      -- starts the string
   OR conditions LIKE '% DIAB1%';   -- preceded by a space
