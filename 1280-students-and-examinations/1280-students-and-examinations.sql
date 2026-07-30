SELECT t1.student_id,
       t1.student_name,
       t3.subject_name,
       COUNT(t2.subject_name) AS attended_exams
FROM Students t1
CROSS JOIN Subjects t3
LEFT JOIN Examinations t2
ON t1.student_id = t2.student_id
AND t3.subject_name = t2.subject_name
GROUP BY t1.student_id, t1.student_name, t3.subject_name
ORDER BY t1.student_id, t3.subject_name;