select p.PRODUCT_ID, p.PRODUCT_NAME, sum(p.PRICE * o.AMOUNT) as TOTAL_SALES
from FOOD_PRODUCT p
inner join FOOD_ORDER o on p.PRODUCT_ID = o.PRODUCT_ID
where o.PRODUCE_DATE like '2022-05%'
group by p.PRODUCT_ID
order by TOTAL_SALES desc, p.PRODUCT_ID