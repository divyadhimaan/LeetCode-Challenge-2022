/* Write your PL/SQL query statement below */
select c.name as Customers 
from Customers c
left join Orders o
on c.Id = o.CustomerId
where o.customerID is NULL
