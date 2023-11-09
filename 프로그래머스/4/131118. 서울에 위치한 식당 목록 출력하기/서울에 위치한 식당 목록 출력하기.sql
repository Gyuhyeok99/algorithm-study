select A.REST_ID, REST_NAME, FOOD_TYPE, FAVORITES, ADDRESS, round(avg(B.REVIEW_SCORE), 2) as score
from REST_INFO A
inner join REST_REVIEW B on A.REST_ID = B.REST_ID
where A.ADDRESS like '서울%'
group by A.REST_ID
order by score desc, FAVORITES desc