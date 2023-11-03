select distinct c.CAR_ID
from CAR_RENTAL_COMPANY_CAR c inner join CAR_RENTAL_COMPANY_RENTAL_HISTORY h 
on c.CAR_ID = h.CAR_ID
where c.CAR_TYPE = '세단' and h.START_DATE like '2022-10%'
order by c.car_ID desc