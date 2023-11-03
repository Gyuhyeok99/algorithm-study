select ORDER_ID, PRODUCT_ID, date_format(OUT_DATE, '%Y-%m-%d') as OUT_DATE, 
(case when DATEDIFF(OUT_DATE, '2022-05-01') <= 0  THEN '출고완료'
      when DATEDIFF(OUT_DATE, '2022-05-01') >  0 THEN '출고대기'
                                        else '출고미정' END
) as '출고여부'
from FOOD_ORDER
order by ORDER_ID