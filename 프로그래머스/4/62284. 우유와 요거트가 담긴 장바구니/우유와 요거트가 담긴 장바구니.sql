SELECT CART_ID
FROM CART_PRODUCTS
where NAME in ('MILK', 'Yogurt')
group by CART_ID
HAVING count(distinct NAME) = 2
order by ID