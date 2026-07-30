SELECT person_name
FROM (
    SELECT person_name,
           turn,
           SUM(weight) OVER (
               ORDER BY turn
               ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW
           ) AS total_weight
    FROM Queue
) t1
WHERE total_weight <= 1000
ORDER BY turn DESC
LIMIT 1;