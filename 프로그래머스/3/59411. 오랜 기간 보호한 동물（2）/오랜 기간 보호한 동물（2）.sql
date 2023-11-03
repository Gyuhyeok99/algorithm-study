SELECT ai.ANIMAL_ID, ai.NAME
from ANIMAL_INS ai 
inner join ANIMAL_OUTS ao on ai.ANIMAL_ID = ao.ANIMAL_ID
order by (ao.DATETIME - ai.DATETIME) desc
limit 2