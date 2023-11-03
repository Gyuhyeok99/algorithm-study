select USER_ID, PRODUCT_Id
from ONLINE_SALE
group by USER_ID, PRODUCT_ID
having count(*) >= 2
order by USER_ID, PRODUCT_ID desc