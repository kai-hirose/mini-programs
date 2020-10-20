create table table1 (id int, username varchar(16), password varchar(32), joindate datetime, constraint id_key primary key (id));
alter table table1 drop primary key;
alter table table1 add constraint new_key primary key(username);
insert into table1 values (1, "testuser", "admin", "2020-10-20 14:56:59");
insert into table1 values (2, "testuser2", "admin", "2020-10-20 14:58:00");
select * from table1 where convert(joindate, date) = date("2020-10-20");
delete from table1 where joindate = "2020-10-20 14:58:00";
select * from table1 where not id = 0 and username = "testuser";