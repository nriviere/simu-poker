CREATE TABLE IF NOT EXISTS `player` (
  `player_id` int(10) unsigned PRIMARY KEY,
  `profile` smallint(6) NOT NULL,
  `profile_level` smallint(6) NOT NULL,
  `hand_count` int(11) NOT NULL,
  `shodown` int(11) NOT NULL,
  `showdown_win` int(11) NOT NULL
)ENGINE=InnoDB DEFAULT CHARSET=UTF8;

CREATE TABLE IF NOT EXISTS `NoSdStat` (
  `player_id` int(10) unsigned PRIMARY KEY,
  `preflop` int(11) NOT NULL,
  `flop` int(11) NOT NULL,
  `turn` int(11) NOT NULL,
  `river` int(11) NOT NULL
)ENGINE=InnoDB DEFAULT CHARSET=UTF8;


CREATE TABLE IF NOT EXISTS `BetStat` (
  `player_id` int(10) unsigned PRIMARY KEY,
  `preflop` int(11) NOT NULL,
  `flop` int(11) NOT NULL,
  `turn` int(11) NOT NULL,
  `river` int(11) NOT NULL
)ENGINE=InnoDB DEFAULT CHARSET=UTF8;

CREATE TABLE IF NOT EXISTS `CallStat` (
  `player_id` int(10) unsigned PRIMARY KEY,
  `preflop` int(11) NOT NULL,
  `flop` int(11) NOT NULL,
  `turn` int(11) NOT NULL,
  `river` int(11) NOT NULL
)ENGINE=InnoDB DEFAULT CHARSET=UTF8;

CREATE TABLE IF NOT EXISTS `RaiseStat` (
  `player_id` int(10) unsigned PRIMARY KEY,
  `preflop` int(11) NOT NULL,
  `flop` int(11) NOT NULL,
  `turn` int(11) NOT NULL,
  `river` int(11) NOT NULL,
  UNIQUE KEY `player_id` (`player_id`)
)ENGINE=InnoDB DEFAULT CHARSET=UTF8;

CREATE TABLE IF NOT EXISTS `AllinStat` (
  `player_id` int(10) unsigned PRIMARY KEY,
  `preflop` int(11) NOT NULL,
  `flop` int(11) NOT NULL,
  `turn` int(11) NOT NULL,
  `river` int(11) NOT NULL,
  UNIQUE KEY `player_id` (`player_id`)
)ENGINE=InnoDB DEFAULT CHARSET=UTF8;

CREATE TABLE IF NOT EXISTS `FoldStat` (
  `player_id` int(10) unsigned PRIMARY KEY,
  `preflop` int(11) NOT NULL,
  `flop` int(11) NOT NULL,
  `turn` int(11) NOT NULL,
  `river` int(11) NOT NULL,
  UNIQUE KEY `player_id` (`player_id`)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8;

CREATE TABLE IF NOT EXISTS `CheckStat` (
  `player_id` int(10) unsigned PRIMARY KEY,
  `preflop` int(11) NOT NULL,
  `flop` int(11) NOT NULL,
  `turn` int(11) NOT NULL,
  `river` int(11) NOT NULL
)ENGINE=InnoDB DEFAULT CHARSET=UTF8;

CREATE TABLE IF NOT EXISTS `AvgRaiseStat` (
  `player_id` int(10) unsigned PRIMARY KEY,
  `preflop` int(11) NOT NULL,
  `flop` int(11) NOT NULL,
  `turn` int(11) NOT NULL,
  `river` int(11) NOT NULL,
  UNIQUE KEY `player_id` (`player_id`)
)ENGINE=InnoDB DEFAULT CHARSET=UTF8;

CREATE TABLE IF NOT EXISTS `PlayerHand` (
  `hand_id` int(10) unsigned,
  `player_id` int(10) unsigned,
  `cards` varchar(4) NOT NULL
)ENGINE=InnoDB DEFAULT CHARSET=UTF8;

CREATE TABLE IF NOT EXISTS `TableBoard` (
  `hand_id` int(10) unsigned,
  `cards` varchar(10) NOT NULL
)ENGINE=InnoDB DEFAULT CHARSET=UTF8;

CREATE TABLE IF NOT EXISTS `TableHandHistory` (
  `hand_id` int(10) unsigned PRIMARY KEY,
  `table_id` int(10) unsigned NOT NULL
)ENGINE=InnoDB DEFAULT CHARSET=UTF8;
