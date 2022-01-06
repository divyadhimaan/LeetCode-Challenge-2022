/* Write your PL/SQL query statement below */
SELECT class 
FROM Courses
HAVING COUNT(student) > 4
GROUP BY class;