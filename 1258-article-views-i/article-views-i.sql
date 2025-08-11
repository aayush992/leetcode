# Write your MySQL query statement below
select distinct author_id AS id from Views 
where viewer_id=author_id 
order by id;