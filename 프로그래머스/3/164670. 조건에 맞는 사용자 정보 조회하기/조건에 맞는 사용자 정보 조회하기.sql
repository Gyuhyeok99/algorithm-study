select u.USER_ID, u.NICKNAME, concat(u.CITY, ' ', u.STREET_ADDRESS1, ' ' ,u.STREET_ADDRESS2) as 전체주소, concat(left(u.tlno, 3), '-', MID(u.tlno, 4, 4), '-', right(u.tlno, 4)) as 전화번호
from USED_GOODS_USER u
inner join USED_GOODS_BOARD b on u.USER_ID = b.WRITER_ID
group by b.WRITER_ID
having count(b.WRITER_ID) >= 3
order by u.USER_ID desc