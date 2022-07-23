CREATE DATABASE db0310;
USE db0310;
CREATE TABLE book
(
	bid INT,
    title VARCHAR(20),
    price DECIMAL(10,2),
    inventory INT
);
INSERT INTO book(bid,title,price,inventory)
VALUES  (1,'A',10.14,100),
		(2,'B',20.12,100),
        (3,'C',124.12,100),
        (4,'D',411.1,100);
SELECT *
FROM book;
        
