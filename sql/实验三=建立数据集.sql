create database hrh1;

go

use hrh1;

CREATE TABLE Student
(
Sno CHAR(9) PRIMARY KEY,
Sname CHAR(20) UNIQUE,
Ssex CHAR(2),
Sage SMALLINT,
Sdept CHAR(20)
);

go

CREATE TABLE  Course
( 
Cno       CHAR(4) PRIMARY KEY,
Cname  CHAR(40),
Cpno     CHAR(4),             	                      
Ccredit  SMALLINT,
FOREIGN KEY (Cpno) REFERENCES  Course(Cno) 
); 

go

CREATE TABLE  SC
(
Sno  CHAR(9),
Cno  CHAR(4),  
Grade    SMALLINT,
primary key (Sno,Cno),
FOREIGN KEY (Sno) REFERENCES Student(Sno),
FOREIGN KEY (Cno) REFERENCES Course(Cno)
); 

go

INSERT INTO Student VALUES('200215121','刘勇','男',20,'CS');
INSERT INTO Student VALUES('200215122','刘晨','女',19,'CS');
INSERT INTO Student VALUES('200215123','王明','女',18,'MA');
INSERT INTO Student VALUES('200215125','张立','男',19,'IS');

go

INSERT INTO Course VALUES(2,'数学',NULL,2);
INSERT INTO Course VALUES(6,'数据处理',NULL,2);
INSERT INTO Course VALUES(4,'操作系统',6,3);
INSERT INTO Course VALUES(7,'PASCAL语言',6,4);
INSERT INTO Course VALUES(5,'数据结构',7,4);
INSERT INTO Course VALUES(1,'数据库',5,4);
INSERT INTO Course VALUES(3,'信息系统',1,4);

go

INSERT INTO SC VALUES('200215121',1,92);
INSERT INTO SC VALUES('200215121',2,85);
INSERT INTO SC VALUES('200215121',3,88);
INSERT INTO SC VALUES('200215122',2,90);
INSERT INTO SC VALUES('200215122',3,80);

go

--- 3.16
SELECT Sno, Sname
FROM Student;

--- 3.17
SELECT Sname, Sno, Sdept
FROM Student;

--- 3.18
SELECT *
FROM Student;

--- 3.19
SELECT Sname, 2014-Sage
FROM Student;

--- 3.20
SELECT Sname, 'Year of Birth:', 2014-Sage, LOWER(Sdept)
FROM Student;

SELECT Sname NAME, 'Year of Birth:' BIRTH, 2014-Sage BIRTHDAY, LOWER(Sdept) DEPARTMENT
FROM Student;

--- 3.21
SELECT Sno
FROM SC;

SELECT DISTINCT Sno
FROM SC;

--- 3.22
SELECT Sname
FROM Student
WHERE Sdept='CS';

--- 3.23
SELECT Sname, Sage
FROM Student
WHERE Sage < 20;

--- 3.24
SELECT DISTINCT Sno
FROM SC
WHERE Grade < 60;

--- 3.25
SELECT Sname, Sdept, Sage
FROM Student
WHERE Sage BETWEEN 20 AND 23;

--- 3.26
SELECT Sname, Sdept, Sage
FROM Student
WHERE Sage NOT BETWEEN 20 AND 23;

--- 3.27
SELECT Sname, Ssex
FROM Student
WHERE Sdept IN ('CS', 'MA', 'IS');

--- 3.28
SELECT Sname, Ssex
FROM Student
WHERE Sdept NOT IN ('CS', 'MA', 'IS');

--- 3.29
SELECT *
FROM Student
WHERE Sno LIKE '201215121';

--- 3.30
SELECT Sname, Sno, Ssex
FROM Student
WHERE Sname LIKE '刘%';

--- 3.31
SELECT Sname
FROM Student
WHERE Sname LIKE '欧阳_';

--- 3.32
SELECT Sname, Sno
FROM Student
WHERE Sname LIKE '_阳%';

--- 3.33
SELECT Sname, Sno, Ssex
FROM Student
WHERE Sname NOT LIKE '刘%';

--- 3.34
SELECT Cno, Ccredit
FROM Course
WHERE Cname LIKE 'DB\_Design' ESCAPE '\';

--- 3.35
SELECT *
FROM Course
WHERE Cname LIKE 'DB\_%i__' ESCAPE '\';

--- 3.36
SELECT Sno, Cno
FROM SC
WHERE Grade IS NULL;

--- 3.37
SELECT Sno, Cno
FROM SC
WHERE Grade IS NOT NULL;

--- 3.38
SELECT Sname
FROM Student
WHERE Sdept='CS' AND Sage<20;

SELECT Sname, Ssex
FROM Student
WHERE Sdept='CS' OR Sdept='MA' OR Sdept='IS';

--- 3.39
SELECT Sno, Grade
FROM SC
WHERE Cno = '3'
ORDER BY Grade DESC;

-- 3.40
SELECT *
FROM Student
ORDER BY Sdept, Sage DESC;

-- 3.41
SELECT COUNT(*)
FROM Student;

-- 3.42
SELECT COUNT(DISTINCT Sno)
FROM SC;

-- 3.43
SELECT AVG(Grade)
FROM SC
WHERE Cno = '1';

-- 3.44
SELECT MAX(Grade)
FROM SC
WHERE Cno='1';

-- 3.45
SELECT SUM(Ccredit)
FROM SC, Course
WHERE Sno='201215012' AND SC.Cno = Course.Cno;

-- 3.46
SELECT Cno, COUNT(Sno)
FROM SC
GROUP BY Cno;

-- 3.47
SELECT Sno
FROM SC
GROUP BY Sno
HAVING COUNT(*) > 3;

-- 3.48
SELECT Sno, AVG(Grade)
FROM SC
GROUP BY Sno
HAVING AVG(Grade) >= 90;

-- 3.49
SELECT Student.*, SC.*
FROM Student, SC
WHERE Student.Sno = SC.Sno;

-- 3.50
SELECT Student.Sno, Sname, Ssex, Sage, Sdept, Cno, Grade
FROM Student, SC
WHERE Student.Sno = SC.Sno;

