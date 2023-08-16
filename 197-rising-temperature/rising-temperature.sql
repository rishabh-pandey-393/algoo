# Write your MySQL query statement below
SELECT W.id FROM Weather AS W INNER JOIN Weather AS WW ON datediff(W.recordDate,WW.recordDate)=1 WHERE W.temperature > WW.temperature 
