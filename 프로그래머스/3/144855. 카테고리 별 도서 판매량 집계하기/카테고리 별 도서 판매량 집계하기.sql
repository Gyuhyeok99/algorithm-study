select b.category, SUM(bs.sales) AS TOTAL_SALES
from BOOK b inner join BOOK_SALES bs on b.BOOK_ID = bs.BOOK_ID
where bs.SALES_DATE like '2022-01%'
group by b.category
order by CATEGORY