CREATE DATABASE db0317;
USE db0317;
CREATE TABLE book
(
	bid CHAR(30) NOT NULL,
    title VARCHAR(30) NOT NULL,
    price DECIMAL(10,2),
    inventory INT,
    PRIMARY KEY (bid),
    check (price > 0)
);
CREATE TABLE `order`
(
	oid CHAR(30) NOT NULL,
    sale_date DATE,
    sale_time TIME,
    bid CHAR(30) NOT NULL,
    quantity INT,
    PRIMARY KEY (oid),
    FOREIGN KEY (bid) REFERENCES book (bid)
);
INSERT INTO book(bid,title,price,inventory)
VALUES  ('001','三国演义',10.14,100),
		('002','水浒传',20.12,100),
        ('003','红楼梦',30.12,100);
INSERT INTO `order`(oid, sale_date, sale_time, bid, quantity)
VALUES	('0001','2022-03-17','20:51:30','001',10),
		('0002',CURDATE(),CURTIME(),'002',30);
select *
FROM book;

select *
FROM `order`;