# Write your MySQL query statement below
SELECT ROUND(COUNT( DISTINCT player_id)/(SELECT COUNT(DISTINCT player_id) FROM Activity),2) AS fraction FROM Activity 
WHERE player_id IN

(SELECT a1.player_id FROM Activity a1
JOIN Activity a2
ON a1.player_id=a2.player_id

 
WHERE a1.event_date = (
        SELECT MIN(event_date)
        FROM Activity
        WHERE player_id = a1.player_id
    )
    AND
DATEDIFF(a2.event_date,a1.event_date)=1
GROUP BY player_id
)