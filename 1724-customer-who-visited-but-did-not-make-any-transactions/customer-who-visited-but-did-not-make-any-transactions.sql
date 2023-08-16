# Write your MySQL query statement below
SELECT V.customer_id, COUNT(V.Customer_id) AS count_no_trans FROM Visits AS V LEFT JOIN Transactions AS T ON V.visit_id=T.visit_id WHERE T.transaction_id IS NULL GROUP BY V.Customer_id ORDER BY count_no_trans