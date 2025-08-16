# Write your MySQL query statement below
select contest_id,
round((count(Register.user_id)*100)/(SELECT COUNT(*) FROM Users),2) as percentage 
from Users join Register on 
Users.user_id=Register.user_id
group by contest_id
order by percentage desc,Register.contest_id asc;