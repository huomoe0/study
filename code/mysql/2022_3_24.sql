# 删除数据库 DROP DATABASE IF EXISTS db10;
CREATE DATABASE db0324;
USE db0324;
CREATE TABLE author
(
	cell_number CHAR(11) UNIQUE,
    name VARCHAR(10) NOT NULL,
    gender ENUM('M','F') NOT NULL,
    email VARCHAR(30) NOT NULL UNIQUE,
    PRIMARY KEY (cell_number)
);
CREATE TABLE book
(
	bid CHAR(30) NOT NULL,
    title VARCHAR(30) NOT NULL,
    press VARCHAR(30),
    pub_date DATE,
    price DECIMAL(10,2),
    inventory INT,
    PRIMARY KEY (bid),
    check (price > 0)
);
CREATE TABLE writing
(
	cell_number CHAR(11),
    bid  CHAR(30) NOT NULL,
    fee DOUBLE DEFAULT (500),
    sub_d DATE,
    sub_t TIME,
    sub_dt DATETIME,
    PRIMARY KEY (cell_number,bid),
    FOREIGN KEY (bid) REFERENCES book (bid),
    FOREIGN KEY (cell_number) REFERENCES author (cell_number)
);
INSERT INTO author(cell_number, name, gender, email)
VALUES	('11111111111','张三','M','zhangsan@qwe.com'),
		('22222222222','李四','M','lisi@qwe.com'),
        ('33333333333','王五','M','wangwu@qwe.com');
INSERT INTO book(bid, title, press, pub_date, price, inventory)
VALUES	('00001','大学物理学','出版社1','2020-11-10',50.50,100),
		('00002','高等数学','出版社2','2020-11-10',50.50,100),
        ('00003','线性代数','出版社3','2020-11-10',50.50,100),
        ('00004','大学物理学','出版社4','2020-11-10',50.50,100),
        ('00005','C语言程序设计','出版社5','2020-11-10',50.50,100);
INSERT INTO writing(cell_number, bid, fee, sub_d, sub_t, sub_dt)
VALUES	('11111111111','00001',550,'2020-11-10','19:20:33','2020-11-10 19:20:33'),
		('22222222222','00002',551,'2020-11-10','11:20:33','2020-11-10 11:20:33'),
        ('33333333333','00003',552,'2020-11-10','13:20:33','2020-11-10 13:20:33'),
        ('11111111111','00004',553,'2020-11-10','14:20:33','2020-11-10 14:20:33');
SELECT *
FROM author;
SELECT *
FROM book;
SELECT *
FROM writing;
describe book;