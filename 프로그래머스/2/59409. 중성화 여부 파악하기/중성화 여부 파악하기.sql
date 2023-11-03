select ANIMAL_ID, NAME, CASE
    WHEN SEX_UPON_INTAKE LIKE 'Neutered%'
    OR SEX_UPON_INTAKE LIKE 'Spayed%'
    THEN 'O'
    ELSE 'X'
END 중성화
from ANIMAL_INS
order by ANIMAL_ID