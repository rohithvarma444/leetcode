SELECT DISTINCT t.id
FROM Weather AS t
JOIN Weather AS x 
  ON x.recordDate = DATE_SUB(t.recordDate, INTERVAL 1 DAY)
WHERE t.temperature > x.temperature;
