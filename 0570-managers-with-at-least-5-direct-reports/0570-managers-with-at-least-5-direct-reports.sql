# Write your MySQL query statement below
select e1.name from Employee as e1 JOIN Employee as e2 ON e1.id = e2.managerID GROUP BY e1.id HAVING COUNT(*) >= 5;