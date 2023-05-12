CREATE DATABASE factory;
USE factory;

CREATE TABLE supplier(
	sid VARCHAR(8) PRIMARY KEY,
	name VARCHAR(10),
	address VARCHAR(10),
	tel CHAR(11),
	account VARCHAR(15)
);
CREATE TABLE supply(
	sid VARCHAR(8),
	eid VARCHAR(8),
	pid VARCHAR(8),
	amount INT,
	PRIMARY KEY (sid, eid, pid),
	FOREIGN KEY (sid) REFERENCES supplier(sid),
	FOREIGN KEY (eid) REFERENCES engineering(eid),
	FOREIGN KEY (pid) REFERENCES part(pid)
);
CREATE TABLE engineering(
	eid VARCHAR(8) PRIMARY KEY,
	budget DECIMAL(15,2),
	date DATE
);
CREATE TABLE part(
	pid VARCHAR(8) PRIMARY KEY,
	name VARCHAR(10),
	specification VARCHAR(10),
	price DECIMAL(10,2),
	description VARCHAR(20)
);
CREATE TABLE warehouse(
	wid VARCHAR(8) PRIMARY KEY,
	area FLOAT,
	tel CHAR(11)
);

CREATE TABLE inventory(
	wid VARCHAR(8),
	pid VARCHAR(8),
	amount INT,
	PRIMARY KEY (wid, pid),
	FOREIGN KEY (wid) REFERENCES warehouse(wid),
	FOREIGN KEY (pid) REFERENCES part(pid)
);

CREATE TABLE worker(
	wid VARCHAR(8) PRIMARY KEY,
	name VARCHAR(10),
	age INT,
	title VARCHAR(10),
	job VARCHAR(10),
	leader VARCHAR(8),
	FOREIGN KEY (leader) REFERENCES worker(wid)
);


CREATE VIEW inventoryVIEW AS
SELECT wid,part.pid,name,specification,amount FROM inventory,part WHERE inventory.pid=part.pid; 

SELECT * FROM inventoryVIEW;


CREATE INDEX workerNameIndex ON worker(name DESC);

CREATE PROCEDURE updateInventory
@twid VARCHAR(8),@tpid VARCHAR(8),@tamount INT
AS
BEGIN
	DECLARE @res INT;
	SELECT amount INTO res FROM inventory WHERE pid=@tpid AND wid=@twid;
	UPDATE inventory SET amount= @res+ @tamount WHERE pid=@tpid AND wid=@twid;
END;

