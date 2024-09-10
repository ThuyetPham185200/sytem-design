# sytem-design with my sql

# create username and pwd for mysql'account
CREATE USER 'demo_user'@'localhost' IDENTIFIED BY 'password';

# if want to providing PRIVILEGES permission to the existed database uisng:
GRANT ALL PRIVILEGES ON demo_db.* TO 'demo_user'@'localhost';
FLUSH PRIVILEGES;

# if want to exit your account using:
EXIT

# to loggin using:
sudo mysql -u demo_user -p

# verify the current user that logging
SELECT USER();

# to create new database
CREATE DATABASE demo_db;

# create use the existed database
USE demo_db;

# to create new table after exit database:
CREATE TABLE employees (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100),
    position VARCHAR(50)
);

# Insert some sample data into the employees table:
INSERT INTO employees (name, position)
VALUES
('Alice', 'Software Engineer'),
('Bob', 'Data Analyst'),
('Charlie', 'Project Manager');

# Query the data:
SELECT * FROM employees;



