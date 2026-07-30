WITH cte AS
(
    SELECT *,
           ROW_NUMBER() OVER (ORDER BY id) AS rn
    FROM Stadium
    WHERE people >= 100
),

grp_cte AS
(
    SELECT *,
           id - rn AS grp
    FROM cte
)

SELECT id,
       visit_date,
       people
FROM grp_cte
WHERE grp IN
(
    SELECT grp
    FROM grp_cte
    GROUP BY grp
    HAVING COUNT(*) >= 3
)
ORDER BY visit_date;