select p.PRODUCT_CODE, SUM(p.PRICE * os.SALES_AMOUNT) as SALES
from PRODUCT p inner join OFFLINE_SALE os on p.PRODUCT_ID = os.PRODUCT_ID
group by p.PRODUCT_CODE
order by SALES desc, p.PRODUCT_CODE