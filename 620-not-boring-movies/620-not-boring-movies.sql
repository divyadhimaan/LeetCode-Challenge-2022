/* Write your PL/SQL query statement below */
SELECT *
FROM Cinema
WHERE MOD(id, 2)!= 0 and description != 'boring'
ORDER BY rating DESC;