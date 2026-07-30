# Write your MySQL query statement below
SELECT p2.product_name, p1.year, p1.price
FROM Sales p1
LEFT JOIN Product p2
ON p1.product_id=p2.product_id

