drop table if exists Scores;
CREATE TABLE IF NOT EXISTS Scores (
    Id INT AUTO_INCREMENT,
    Score DECIMAL(3 , 2 ),
    primary key (Id)
);

insert into Scores(score) values (3.5),(3.65),(4.00),(3.85),(4.00),(3.65);

select score, row() from Scores group by score order by score desc;


SELECT 
    Score,
    CASE
        WHEN @pre_score = tmp.score THEN @j
        ELSE @j:=@j + 1
    END Rank,
    @pre_score:=tmp.score AS pre_score
FROM
    (SELECT 
        *
    FROM
        Scores
    ORDER BY score DESC) tmp,
    (SELECT @k:=0, @j:=0, @pre_score:=0) sdcore;

    
select 
t1.Score,
(select count(*) from (select distinct score from scores) t2 where t2.score >=t1.Score) rank
from scores t1 order by score desc;