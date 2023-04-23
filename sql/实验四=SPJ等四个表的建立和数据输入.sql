create database SPJ;
go

use SPJ;
go

create table S
(SNO char(9) PRIMARY KEY,
SNAME CHAR(10),
STATUS INT,
CITY CHAR(10)
);



create table P
(PNO char(9) PRIMARY KEY,
PNAME CHAR(10),
COLOR CHAR(10),
WEIGHT INT
);


create table J
(JNO char(9) PRIMARY KEY,
JNAME CHAR(10),
CITY CHAR(10)
);

go

create table SPJ
(SNO char(9),
PNO CHAR(9),
JNO CHAR(9),
QTY INT,
PRIMARY KEY(SNO,PNO,JNO),
FOREIGN KEY(SNO) REFERENCES S(SNO),
FOREIGN KEY(PNO) REFERENCES P(PNO),
FOREIGN KEY(JNO) REFERENCES J(JNO),
);


go

Insert into S(SNO,SNAME,STATUS,CITY)
Values('S1','精益',20,'天津');
Insert into S(SNO,SNAME,STATUS,CITY)
Values('S2','盛锡',10,'北京');
Insert into S(SNO,SNAME,STATUS,CITY)
Values('S3','东方红',30,'北京');
Insert into S(SNO,SNAME,STATUS,CITY)
Values('S4','丰泰盛',20,'天津');
Insert into S(SNO,SNAME,STATUS,CITY)
Values('S5','为民',30,'上海');


Insert into P(PNO,PNAME,COLOR,WEIGHT)
Values('P1','螺母','红',12);
Insert into P(PNO,PNAME,COLOR,WEIGHT)
Values('P2','螺栓','绿',17);
Insert into P(PNO,PNAME,COLOR,WEIGHT)
Values('P3','螺丝刀','蓝',14);
Insert into P(PNO,PNAME,COLOR,WEIGHT)
Values('P4','螺丝刀','红',14);
Insert into P(PNO,PNAME,COLOR,WEIGHT)
Values('P5','凸轮','蓝',40);
Insert into P(PNO,PNAME,COLOR,WEIGHT)
Values('P6','齿轮','红',30);


Insert into J(JNO,JNAME,CITY)
Values('J1','三建','北京');
Insert into J(JNO,JNAME,CITY)
Values('J2','一汽','长春');
Insert into J(JNO,JNAME,CITY)
Values('J3','弹簧厂','天津');
Insert into J(JNO,JNAME,CITY)
Values('J4','造船厂','天津');
Insert into J(JNO,JNAME,CITY)
Values('J5','机车厂','唐山');
Insert into J(JNO,JNAME,CITY)
Values('J6','无线电厂','常州');
Insert into J(JNO,JNAME,CITY)
Values('J7','半导体厂','南京');

go


Insert into SPJ(SNO,PNO,JNO,QTY) 
values('S1','P1','J1',200);
Insert into SPJ(SNO,PNO,JNO,QTY)
 values('S1','P1','J3',100);
Insert into SPJ(SNO,PNO,JNO,QTY)
 values('S1','P1','J4',700);
Insert into SPJ(SNO,PNO,JNO,QTY)
 values('S1','P2','J2',100);
Insert into SPJ(SNO,PNO,JNO,QTY) 
values('S2','P3','J1',400);
Insert into SPJ(SNO,PNO,JNO,QTY) 
values('S2','P3','J2',200);
Insert into SPJ(SNO,PNO,JNO,QTY) 
values('S2','P3','J4',500);
Insert into SPJ(SNO,PNO,JNO,QTY)
 values('S2','P3','J5',400);
Insert into SPJ(SNO,PNO,JNO,QTY)
 values('S2','P5','J1',400);
Insert into SPJ(SNO,PNO,JNO,QTY) 
values('S2','P5','J2',100);
Insert into SPJ(SNO,PNO,JNO,QTY) 
values('S3','P1','J1',200);
Insert into SPJ(SNO,PNO,JNO,QTY)
 values('S3','P3','J1',200);
Insert into SPJ(SNO,PNO,JNO,QTY)
 values('S4','P5','J1',100);
Insert into SPJ(SNO,PNO,JNO,QTY)
 values('S4','P6','J3',300);
Insert into SPJ(SNO,PNO,JNO,QTY)
 values('S4','P6','J4',200);
Insert into SPJ(SNO,PNO,JNO,QTY)
 values('S5','P2','J4',100);
Insert into SPJ(SNO,PNO,JNO,QTY)
 values('S5','P3','J1',200);
Insert into SPJ(SNO,PNO,JNO,QTY)
 values('S5','P6','J2',200);
Insert into SPJ(SNO,PNO,JNO,QTY) 
 values('S5','P6','J4',500);

select * from S;
select * from P;
select * from J;
select * from SPJ;


-- 5.1
SELECT SNAME, CITY
FROM S;

-- 5.2
SELECT PNAME, COLOR, WEIGHT
FROM P;

-- 5.3
SELECT DISTINCT JNO
FROM SPJ
WHERE SNO = 'S1';

-- 5.4
SELECT PNAME, QTY
FROM SPJ, P
WHERE SPJ.PNO = P.PNO AND JNO = 'J2';

-- 5.5
SELECT DISTINCT PNO
FROM SPJ
WHERE SNO IN (SELECT SNO FROM S WHERE CITY = '上海');

-- 5.6
SELECT DISTINCT JNAME
FROM J, SPJ, S
WHERE J.JNO = SPJ.JNO AND S.SNO = SPJ.SNO AND S.CITY = '上海';

-- 5.7
SELECT DISTINCT JNO
FROM J
WHERE NOT EXISTS 
							(SELECT * FROM SPJ WHERE SPJ.JNO = J.JNO AND SNO IN 
																																(SELECT SNO FROM S WHERE CITY = '天津'));

-- 5.8
UPDATE P
SET COLOR = '蓝'
WHERE COLOR = '红';

-- 5.9
UPDATE SPJ
SET SNO = 'S3'
WHERE JNO = 'J4' AND PNO = 'P6' AND SNO = 'S5';

SELECT *
FROM SPJ
WHERE JNO = 'J4';

-- 5.10
DELETE FROM SPJ
WHERE SNO = 'S2';

DELETE FROM S
WHERE SNO = 'S2';

-- 5.11
INSERT INTO S(SNO,SNAME,STATUS,CITY)
VALUES ('S2','盛锡',10,'北京');

INSERT INTO SPJ(SNO, PNO, JNO, QTY)
VALUES ('S2', 'P4', 'J6', 200);

-- 9.1
CREATE VIEW SPQ
AS 
SELECT S.SNO, PNO, QTY
FROM S, SPJ
WHERE S.SNO = SPJ.SNO AND JNO IN (SELECT JNO FROM J WHERE JNAME = '三建');

SELECT *
FROM SPQ;

-- 9.2
SELECT PNO, SUM(QTY)
FROM SPQ
WHERE SNO = 'S1'
GROUP BY PNO;

