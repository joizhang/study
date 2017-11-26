drop table if exists Employee;
CREATE TABLE IF NOT EXISTS Employee (
    Id INT AUTO_INCREMENT,
    Salary INT,
    PRIMARY KEY (Id)
);

insert into Employee (salary) values (100),(200),(300);

SELECT 
    distinct Salary SecondHighestSalary
FROM
    employee
ORDER BY salary DESC
LIMIT 1 , 1;

SELECT 
    MAX(salary) SecondHighestSalary
FROM
    employee
WHERE
    salary < (SELECT 
            MAX(salary) SecondHighestSalary
        FROM
            employee);