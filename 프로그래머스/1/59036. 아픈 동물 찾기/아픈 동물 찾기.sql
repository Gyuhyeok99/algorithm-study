# SELECT ANIMAL_ID, NAME 
# FROM ANIMAL_INS 
# WHERE INTAKE_CONDITION='Sick'












select animal_id, name
from ANIMAL_INS as a
where a.INTAKE_CONDITION = 'Sick'
order by animal_id;