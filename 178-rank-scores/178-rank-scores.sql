SELECT SCORE,RN AS RANK FROM(
SELECT ID,SCORE,DENSE_RANK()OVER(ORDER BY SCORE DESC) AS RN
FROM SCORES) RES