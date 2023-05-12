
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


use SPJ;
go

CREATE TRIGGER P_INSERT ON P AFTER INSERT
AS
BEGIN
	IF (SELECT WEIGHT FROM INSERTED) NOT BETWEEN 0 AND 100
	BEGIN
		PRINT 'WEIGHT值必须在0到100之间！'
		ROLLBACK TRANSACTION
	END
	ELSE
	BEGIN
		PRINT '插入成功！'
	END
END
GO


CREATE TRIGGER P_INSTEADOF_INSERT ON P INSTEAD OF INSERT
AS
BEGIN
DECLARE
	@PPNO CHAR,
	@PPNAME CHAR,
	@PCOLOR CHAR,
	@PWEIGHT INT

	SET @PPNO=(SELECT PNO FROM INSERTED)
	SET @PPNAME=(SELECT PNAME FROM INSERTED)
	SET @PCOLOR=(SELECT COLOR FROM INSERTED)
	SET @PWEIGHT=(SELECT WEIGHT FROM INSERTED)

	IF (SELECT WEIGHT FROM INSERTED) NOT BETWEEN 0 AND 100
		PRINT 'WEIGHT值必须在0到100之间！'
	ELSE
		BEGIN
		INSERT INTO P VALUES(@PPNO,@PPNAME,@PCOLOR,@PWEIGHT)
		PRINT '插入成功！'
		END
END
GO


INSERT INTO P VALUES('P7','SS','SS',200);

INSERT INTO P VALUES('P8','TT','TT',99);

SELECT * FROM P;

DELETE FROM P WHERE WEIGHT>50;

SELECT * FROM P;

DROP TRIGGER P_INSERT;

DROP TRIGGER P_INSTEADOF_INSERT;
-------------------------------
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


use hrh1;
go

create procedure sgrade
as
select Student.sno, sname, cname, grade from Student,SC,Course
where Student.sno=SC.sno and Course.cno=SC.cno;

go

exec sgrade
go


create procedure ssname @s_name char(20)
as
select avg(grade) as '平均成绩'
from Student,SC where SC.Sno=Student.Sno and sname=@s_name;

go
select * from Student;
exec ssname '刘勇';
exec ssname '王明';
go

create procedure studentinfo @s_name char(20)
as
declare @s_count int
declare @s_avg real
select @s_count=count(cno),@s_avg=avg(grade) from student,SC where Student.sno=SC.sno and Student.sname=@s_name

print @s_name+'同学共选修了'+str(@s_count)+'门课程，平均成绩为'+str(@s_avg)

go

exec studentinfo '刘勇';
exec studentinfo '王明';
go


alter procedure ssname @s_name char(20)
as
declare @savg int
select @savg=avg(grade) from Student,SC where Student.sno=SC.sno and sname=@s_name
if @savg>60
	print '此学生综合成绩合格，成绩为'+convert(char(2),@savg)+'分'
else
	print '此学生综合成绩不及格，成绩为'+convert(char(2),@savg)+'分'
go


drop procedure ssname
go

