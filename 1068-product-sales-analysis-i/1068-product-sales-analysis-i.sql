# Write your MySQL query statement below
SELECT Product.product_name, year, price
FROM Sales 
JOIN Product ON Sales.product_id =  Product.product_id;
