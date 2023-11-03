select ai.ANIMAL_ID, ai.name
from ANIMAL_INS ai inner join ANIMAL_OUTS ao on ai.ANIMAL_ID = ao.ANIMAL_ID
where ai.DATETIME > ao.DATETIME
order by ai.dateTIme