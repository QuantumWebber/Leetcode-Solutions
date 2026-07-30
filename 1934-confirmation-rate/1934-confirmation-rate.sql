SELECT t1.user_id,
ROUND(
IFNULL(SUM(t2.action='confirmed') / COUNT(t2.action),0),2
) AS confirmation_rate
FROM Signups t1
LEFT JOIN Confirmations t2
ON t1.user_id = t2.user_id
GROUP BY t1.user_id;