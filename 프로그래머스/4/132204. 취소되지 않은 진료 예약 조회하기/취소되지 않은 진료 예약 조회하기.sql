select a.APNT_NO, p.PT_NAME, p.PT_NO, d.MCDP_CD, d.DR_NAME, a.APNT_YMD
from APPOINTMENT a 
inner join PATIENT p on a.PT_NO = p.PT_NO
inner join DOCTOR d on a.MDDR_ID = d.DR_ID
where d.MCDP_CD = 'CS' and a.APNT_CNCL_YN = 'N' and a.APNT_YMD like '2022-04%' and a.APNT_CNCL_YMD is null
order by a.APNT_YMD