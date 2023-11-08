select year(SALES_DATE) as YEAR, month(SALES_DATE) as MONTH, gender, count(distinct os.USER_ID) as USERS
from ONLINE_SALE os
inner join USER_INFO ui on os.USER_ID = ui.USER_ID
where gender is not null
group by YEAR, MONTH, gender
order by YEAR, MONTH, GENDER