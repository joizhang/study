#如何正确的使用Join从句

##环境
Server version: 5.5.52-0ubuntu0.14.04.1 (Ubuntu)

##建表
create database imoocmysql;
use imoocmysql;

drop table if exists t_a;
create table t_a(
id int not null AUTO_INCREMENT,
user_name varchar(32) not null,
position varchar(32),
final varchar(16),
PRIMARY KEY(id)
)ENGINE=Innodb DEFAULT CHARSET=utf8;

insert into t_a (user_name, position, final) values ('孙悟空','斗战胜佛','佛'), ('唐僧','无量功德佛',''),('猪八戒','净坛使者',''),('沙和尚','罗汉','');

drop table if exists t_b;
create table t_b(
id int not null auto_increment,
user_name varchar(32) not null,
primary key(id)
)ENGINE=Innodb DEFAULT CHARSET=utf8;

insert into t_b (user_name) values('孙悟空'), ('牛魔王'), ('鹏魔王'),('蛟魔王'),('狮驼王');


##join操作的类型-inner join
内连接inner join基于连接谓词将两张表的列组合在一起，产生新的结果表(交集)
选出a和b中id相同的：
select a.*,b.* from t_a a inner join t_b b on a.user_name=b.user_name;
+----+-----------+--------------+-------+----+-----------+
| id | user_name | position     | final | id | user_name |
+----+-----------+--------------+-------+----+-----------+
|  1 | 孙悟空    | 斗战胜佛     | 佛    |  1 | 孙悟空    |
+----+-----------+--------------+-------+----+-----------+


##Join操作的类型-left outer join
1.没有条件的情况下左表所有记录会被查询出来
2.只存在于a不存在于b的记录
select a.*,b.* from t_a a left join t_b b on a.user_name=b.user_name where b.user_name is null;
+----+-----------+-----------------+-------+------+-----------+
| id | user_name | position        | final | id   | user_name |
+----+-----------+-----------------+-------+------+-----------+
|  2 | 唐僧      | 无量功德佛      |       | NULL | NULL      |
|  3 | 猪八戒    | 净坛使者        |       | NULL | NULL      |
|  4 | 沙和尚    | 罗汉            |       | NULL | NULL      |
+----+-----------+-----------------+-------+------+-----------+

##Join操作的类型-right outer join
1.没有条件的情况下右表所有记录会被查询出来
2.select a.*,b.* from t_a a right join t_b b on a.user_name=b.user_name where a.user_name is null;
+------+-----------+----------+-------+----+-----------+
| id   | user_name | position | final | id | user_name |
+------+-----------+----------+-------+----+-----------+
| NULL | NULL      | NULL     | NULL  |  2 | 牛魔王    |
| NULL | NULL      | NULL     | NULL  |  3 | 鹏魔王    |
| NULL | NULL      | NULL     | NULL  |  4 | 蛟魔王    |
| NULL | NULL      | NULL     | NULL  |  5 | 狮驼王    |
+------+-----------+----------+-------+----+-----------+

##Join操作的类型-full join
1.全部查询
select * from t_a a full join t_b b on a.user_name=b.user_name;
不支持
left join right join union All

2.过滤有交集的部分

##Join操作的类型-cross join
交叉连接，又称笛卡尔连接或叉乘，如果a和b是两个集合，它们的交叉连接就记为A乘以B
select * from t_a a cross join t_b b;
+----+-----------+-----------------+-------+----+-----------+
| id | user_name | position        | final | id | user_name |
+----+-----------+-----------------+-------+----+-----------+
|  1 | 孙悟空    | 斗战胜佛        | 佛    |  1 | 孙悟空    |
|  2 | 唐僧      | 无量功德佛      |       |  1 | 孙悟空    |
|  3 | 猪八戒    | 净坛使者        |       |  1 | 孙悟空    |
|  4 | 沙和尚    | 罗汉            |       |  1 | 孙悟空    |
|  1 | 孙悟空    | 斗战胜佛        | 佛    |  2 | 牛魔王    |
|  2 | 唐僧      | 无量功德佛      |       |  2 | 牛魔王    |
|  3 | 猪八戒    | 净坛使者        |       |  2 | 牛魔王    |
|  4 | 沙和尚    | 罗汉            |       |  2 | 牛魔王    |
|  1 | 孙悟空    | 斗战胜佛        | 佛    |  3 | 鹏魔王    |
|  2 | 唐僧      | 无量功德佛      |       |  3 | 鹏魔王    |
|  3 | 猪八戒    | 净坛使者        |       |  3 | 鹏魔王    |
|  4 | 沙和尚    | 罗汉            |       |  3 | 鹏魔王    |
|  1 | 孙悟空    | 斗战胜佛        | 佛    |  4 | 蛟魔王    |
|  2 | 唐僧      | 无量功德佛      |       |  4 | 蛟魔王    |
|  3 | 猪八戒    | 净坛使者        |       |  4 | 蛟魔王    |
|  4 | 沙和尚    | 罗汉            |       |  4 | 蛟魔王    |
|  1 | 孙悟空    | 斗战胜佛        | 佛    |  5 | 狮驼王    |
|  2 | 唐僧      | 无量功德佛      |       |  5 | 狮驼王    |
|  3 | 猪八戒    | 净坛使者        |       |  5 | 狮驼王    |
|  4 | 沙和尚    | 罗汉            |       |  5 | 狮驼王    |
+----+-----------+-----------------+-------+----+-----------+


##join相关技巧

###1.把同时存在与取经四人组和悟空兄弟表中的记录的人在取经四人组中的position更新为“齐天大圣”
updata t_a set t_a.position='齐天大圣' where t_a.user_name in (
select a.user_name from t_a a inner join t_b b where a.user_name=b.user_name
);
无法执行
updata t_a a join (select a.user_name from t_a a inner join t_b b where a.user_name=b.user_name) b on a.user_name=b.user_name set a.position='齐天大圣';
也没有成功，版本问题？






