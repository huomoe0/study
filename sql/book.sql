CREATE DATABASE book;

USE book;

CREATE TABLE customers (
	cid CHAR(20) PRIMARY KEY,
	cname CHAR(16),
	address VARCHAR(20),
	cardnumber CHAR(20)

);

CREATE TABLE books (
	lsbn CHAR(17) PRIMARY KEY,
	title VARCHAR(20),
	author VARCHAR(8),
	price DECIMAL(10, 2),
	year_publisher datetime,
	qty_in_stock INT
);

CREATE TABLE orders (
    ordernum CHAR(20) PRIMARY KEY
);