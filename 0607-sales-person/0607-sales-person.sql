SELECT name
FROM SalesPerson
WHERE sales_id NOT IN (
    SELECT t1.sales_id
    FROM (
        SELECT s1.sales_id, o1.com_id
        FROM SalesPerson s1
        LEFT JOIN Orders o1
        ON s1.sales_id = o1.sales_id
    ) t1
    JOIN Company c1
    ON t1.com_id = c1.com_id
    WHERE c1.name = 'RED'
);