USE university;

SELECT c_id,grade
FROM takes JOIN student ON student.s_id = takes.s_id
WHERE name = '李一'
ORDER BY student.s_id;

SELECT takes.c_id,title,credit
FROM takes JOIN course ON takes.c_id = course.c_id
WHERE s_id IN (SELECT s_id FROM student WHERE dept_name = '计算机科学')
ORDER BY c_id;

SELECT name,title,grade
FROM student JOIN takes ON student.s_id = takes.s_id
			JOIN course ON takes.c_id = course.c_id
WHERE grade < 80
ORDER BY student.s_id;