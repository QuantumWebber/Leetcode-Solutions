# Write your MySQL query statement below



-- dono requester id aur acceptor id mei bando ka count nikl lo jiska count zada hoga dono ka milake wo ans with total count 


SELECT id, COUNT(*) AS num
FROM (
    SELECT requester_id AS id
    FROM RequestAccepted

    UNION ALL

    SELECT accepter_id AS id
    FROM RequestAccepted
) t
GROUP BY id
ORDER BY COUNT(*) DESC
LIMIT 1;