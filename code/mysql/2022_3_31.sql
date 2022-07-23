DROP DATABASE IF EXISTS university;

CREATE DATABASE university;

USE university;

# 学院(学院名称，所在位置，经费预算)
CREATE TABLE department (
    dept_name VARCHAR(20),
    building VARCHAR(20),
    budget DECIMAL(12, 2),
    PRIMARY KEY (dept_name),
    CHECK (budget > 0)
);

# 学生(学号，姓名，性别，出生日期，学院名称)
CREATE TABLE student (
    s_id CHAR(3),
    name VARCHAR(30) NOT NULL,
    gender ENUM('M', 'F') NOT NULL,
    birthday DATE,
    dept_name VARCHAR(20),
    PRIMARY KEY (s_id),
    FOREIGN KEY (dept_name) REFERENCES department (dept_name)
);

# 课程 (课程号，课程名，先修课程号，学分)
CREATE TABLE course (
    c_id CHAR(2),
    title VARCHAR(30) NOT NULL DEFAULT '数据库',
    p_id CHAR(2),
    credit TINYINT UNSIGNED DEFAULT 3,
    PRIMARY KEY (c_id),
    UNIQUE (title),
    FOREIGN KEY (p_id) REFERENCES course (c_id),
    CHECK (credit >= 1 AND credit <= 6)
);

# 选修 (学号，课程号，成绩)
CREATE TABLE takes (
    s_id CHAR(3),
    c_id CHAR(2),
    grade NUMERIC(4, 1),
    PRIMARY KEY (s_id, c_id),
    FOREIGN KEY (s_id) REFERENCES student (s_id),
    FOREIGN KEY (c_id) REFERENCES course (c_id),
    CHECK (grade >= 0 AND grade <= 100)
);



# 插入数据

INSERT INTO department (dept_name, building, budget)
VALUES  ('生物', '3号楼', 90000),
        ('计算机科学', '2号楼', 100000),
        ('电子工程', '2号楼', 85000),
        ('金融', '1号楼', 120000),
        ('历史', '1号楼', 80000),
        ('音乐', '1号楼', 80000),
        ('物理', '4号楼', 70000);

INSERT INTO student (s_id, name, gender, birthday, dept_name)
VALUES	('001', '李一', 'M', '1998-06-15', '计算机科学'),
        ('002', '李二', 'M', NULL, '电子工程'),
        ('003', '李三', 'M', '1998-07-20', NULL),
        ('004', '李四', 'F', NULL, '计算机科学'),
        ('005', '李五', 'F', '1998-06-25', '音乐'),
        ('006', '李六', 'F', NULL, '物理');


INSERT INTO course (c_id, title, p_id, credit)
VALUES  ('01', '高等数学', NULL, 6),
        ('02', '计算机导论', NULL, 3),
        ('03', 'C语言程序设计', '02', 5),
        ('04', '数据结构', '03', 4),
        ('05', DEFAULT, '04', DEFAULT);

INSERT INTO takes (s_id, c_id, grade)
VALUES  ('001', '01', 90),
        ('001', '02', 95),
        ('001', '03', NULL),
        ('001', '04', 85),
        ('001', '05', 90),
        ('002', '01', NULL),
        ('002', '02', 88.5),
        ('002', '03', 75),
        ('002', '04', 85.5),
        ('003', '01', 60),
        ('003', '02', 95),
        ('004', '01', 70),
        ('004', '02', 72),
        ('005', '01', 80),
        ('005', '02', 81),
        ('006', '01', 80);
#2
SELECT *
FROM student;
UPDATE student
SET birthday = '1999-12-03'
WHERE s_id = '002';
SELECT *
FROM student;
#3
SELECT *
FROM student;
UPDATE student
SET birthday = NULL
WHERE s_id = '005';
SELECT *
FROM student;
#4
SELECT *
FROM student;
UPDATE student
SET birthday = '1999-12-03',dept_name = '生物'
WHERE s_id = '004';
SELECT *
FROM student;
#5
SELECT *
FROM takes;
UPDATE takes
SET grade = grade + 1
WHERE s_id = '002';
SELECT *
FROM takes;
#6
SELECT *
FROM department;
UPDATE department
SET budget = budget * 0.85
WHERE dept_name = '历史';
SELECT *
FROM department;
#7
SELECT *
FROM takes;
UPDATE takes
SET grade = grade - 5;
SELECT *
FROM takes;
#8
SELECT *
FROM department;
DELETE FROM department
WHERE dept_name = '金融';
SELECT *
FROM department;
#9
SELECT *
FROM department;
DELETE FROM takes
WHERE s_id = '005';
DELETE FROM student
WHERE s_id = '005';
DELETE FROM department
WHERE dept_name = '音乐';
SELECT *
FROM department;
#10
DELETE FROM takes;
UPDATE course
SET p_id = NULL;
DELETE FROM course;
DELETE FROM student;
DELETE FROM department;
SELECT *
FROM takes;
SELECT *
FROM course;
SELECT *
FROM student;
SELECT *
FROM department;
#11
DROP TABLE IF EXISTS takes;
DROP TABLE IF EXISTS course;
DROP TABLE IF EXISTS student;
DROP TABLE IF EXISTS department;
#12
DROP DATABASE IF EXISTS university;
