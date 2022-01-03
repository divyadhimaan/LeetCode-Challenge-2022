/* Write your PL/SQL query statement below */

SELECT w1.Id
FROM Weather w1 join Weather w2 on w1.Temperature > w2.Temperature AND
TO_DAte(w1.recordDate )-TO_DAte(w2.recordDate )=1;