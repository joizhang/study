-- hash 索引
drop table if exists pseudohash;
create table pseudohash (
  id int unsigned not null auto_increment,
  url varchar(255) not null,
  url_crc int unsigned not null default 0,
  primary key(id)
);

drop trigger if exists pseudohash_crc_ins;
drop trigger if exists pseudohash_crc_upd;
delimiter //

create trigger pseudohash_crc_ins before insert on pseudohash for each row begin
set NEW.url_crc=crc32(NEW.url);
end;
//

create trigger pseudohash_crc_upd before update on pseudohash for each row begin
set NEW.url_crc=crc32(NEW.url);
end;
//

delimiter ;

delete from pseudohash where id in (1, 2, 3, 4);

insert into pseudohash (url) values ('http://www.mysql.com');
select * from pseudohash;

update pseudohash set url='http://www.mysql.com' where id=1;
select * from pseudohash where url_crc = crc32('http://www.mysql.com');

select crc32('http://www.mysql.com') from pseudohash
