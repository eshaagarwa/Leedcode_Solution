# Write your MySQL query statement below
SELECT DISTINCT l1.Num as ConsecutiveNums
FROM Logs l1, Logs l2, Logs l3
WHERE l2.Id = l1.Id - 1 and l3.Id = l1.Id - 2 and l1.Num = l2.Num and l3.Num = l1.Num;