-- 5.3.1 独立的列
-- select actor id from actor where actor_id + 1 = 5; -- 无法使用索引

-- 5.3.2 前缀索引和索引选择性
drop table if exists city_demo;
create table city_demo(
  city varchar(50) not null
);

-- 创建前缀索引
alter table city_demo add key (city(7));

show create table city_demo;

-- 5.3.3
