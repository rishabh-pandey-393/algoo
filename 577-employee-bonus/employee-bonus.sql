# Write your MySQL query statement below
SELECT E.name as name, B.bonus as bonus FROM Employee AS E LEFT JOIN Bonus AS B ON E.empId=B.empId WHERE bonus<1000 or bonus IS NULL