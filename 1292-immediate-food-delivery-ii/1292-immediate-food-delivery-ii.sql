SELECT 
    ROUND(SUM(IF(order_date = customer_pref_delivery_date, 1, 0) * 100) / COUNT(delivery_id), 2) AS immediate_percentage
FROM Delivery
WHERE (customer_id,order_date) in (SELECT customer_id , MIN(order_date) FROM Delivery group by customer_id);