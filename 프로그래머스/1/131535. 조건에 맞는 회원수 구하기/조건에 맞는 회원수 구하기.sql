select count(*) as USERS
from USER_INFO
where year(JOINED) = 2021 and age >= 20 and age <= 29