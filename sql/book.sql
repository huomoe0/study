CREATE DATABASE book;

USE book;

CREATE TABLE customers (
	cid VARCHAR(10) PRIMARY KEY,
	cname VARCHAR(16) NOT NULL,
	address VARCHAR(30) NOT NULL,
	cardnum CHAR(20) NOT NULL
);
CREATE TABLE orders (
    ordernum VARCHAR(10) PRIMARY KEY
);
CREATE TABLE books (
	lsbn CHAR(20) PRIMARY KEY,
	title VARCHAR(20) NOT NULL,
	author VARCHAR(8),
	qty_in_stock INT NOT NULL,
	price MONEY,
	year_published DATE
);

CREATE TABLE place_order (
	cid VARCHAR(10) FOREIGN KEY REFERENCES customers(cid),
	ordernum VARCHAR(10) FOREIGN KEY REFERENCES orders(ordernum),
	order_date DATETIME NOT NULL,
	PRIMARY KEY(cid,ordernum)
);

CREATE TABLE order_list (
	ordernum VARCHAR(10) FOREIGN KEY REFERENCES orders(ordernum),
	isbn CHAR(20) FOREIGN KEY REFERENCES books(lsbn),
	qty INT NOT NULL,
	ship_date DATETIME,
	PRIMARY KEY(ordernum, isbn)
);
