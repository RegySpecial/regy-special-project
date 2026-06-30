/*
@author RegySpecial
@description SQLite script to interact with the videogame database
@role SQL script
@date (first version [SQLite]) 2026 March 30th Monday 21:57:57 (Sun hour)
*/
create table if not exists users(
  identifier integer primary key autoincrement,
  name varchar(40) not null
);
create table if not exists locations(
  identifier integer primary key autoincrement,
  name varchar(40) not null,
  type bit(3) default 0,
  constraint typeFiledRange
  check (type between 0 and 4)
);
create table if not exists items(
  identifier integer primary key autoincrement,
  name varchar(40) not null,
  userIdentifier integer,
  constraint pointerToUserIdentifier
  foreign key (userIdentifier)
  references users(identifier)
);
create table if not exists options(
  musicVolume bit(8) default 127,
  soundVolume bit(8) default 127,
  language varchar(2) default "en",
  constraint checkLanguage
  check (language in ("it","en","fr","de","es","ch"))
);
