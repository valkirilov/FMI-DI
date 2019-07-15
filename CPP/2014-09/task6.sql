CREATE TABLE classes(
    class VARCHAR(64),
    type VARCHAR(2),
    country VARCHAR(64),
    numguns INT,
    bore INT,
    displacement INT,
    PRIMARY KEY (class)
);

CREATE TABLE ships(
    name VARCHAR(64),
    class VARCHAR(64),
    launched INT(4),
    PRIMARY KEY (name),
    FOREIGN KEY (class) REFERENCES classes(class)
);

CREATE TABLE battles(
    name VARCHAR(64),
    date DATE,
    PRIMARY KEY (name)
);

CREATE TABLE outcomes(
    ship VARCHAR(64),
    battle VARCHAR(64),
    RESULT VARCHAR(32),
    PRIMARY KEY (ship, battle),
    FOREIGN KEY (ship) REFERENCES ships(name),
    FOREIGN KEY (battle) REFERENCES battles(name)
);

INSERT INTO `classes`(`class`, `type`, `country`, `numguns`, `bore`, `displacement`) VALUES
("CLASS 1", "bb", "England", 1, 2, 3),
("CLASS 2", "bc", "Germany", 3, 4, 5),
("CLASS 3", "bb", "Russia", 4, 12, 13),
("CLASS 4", "bc", "Italy", 21, 3, 5),
("CLASS 5", "bc", "America", 21, 3, 5);

INSERT INTO `ships`(`name`, `class`, `launched`) VALUES
("SHIP 1", "CLASS 1", 1914),
("SHIP 2", "CLASS 1", 1939),
("SHIP 3", "CLASS 1", 1939),
("SHIP 4", "CLASS 1", 1939),
("SHIP 5", "CLASS 2", 1945),
("SHIP 6", "CLASS 2", 1945),
("SHIP 7", "CLASS 3", 1945),
("SHIP 8", "CLASS 3", 1944),
("SHIP 9", "CLASS 4", 1944);

INSERT INTO `battles`(`name`, `date`)
VALUES ("BATTLE 1", "1938-03-15 12:36:45"),
("BATTLE 2", "1939-02-05 15:42:65"),
("BATTLE 3", "1945-05-16 08:12:15"),
("BATTLE 4", "1945-05-16 08:12:15"),
("BATTLE 5", "1945-05-16 08:12:15"),
("BATTLE 6", "1945-05-16 08:12:15"),
("BATTLE 7", "1945-05-16 08:12:15"),
("BATTLE 8", "1945-05-16 08:12:15"),
("BATTLE 9", "1945-05-16 08:12:15");

INSERT INTO `outcomes`(`ship`, `battle`, `result`)
VALUES ("SHIP 1", "BATTLE 1", "ok"),
("SHIP 5", "BATTLE 2", "sunk"),
("SHIP 5", "BATTLE 3", "damaged"),
("SHIP 5", "BATTLE 4", "damaged"),
("SHIP 5", "BATTLE 5", "damaged"),
("SHIP 5", "BATTLE 6", "damaged"),
("SHIP 4", "BATTLE 7", "damaged"),
("SHIP 4", "BATTLE 8", "damaged"),
("SHIP 4", "BATTLE 9", "damaged");

/* Task 1 */
select distinct NAME
from SHIPS
join BATTLES
on LAUNCHED = year(DATE);

SELECT DISTINCT SHIPS.NAME
FROM BATTLES, SHIPS
WHERE LAUNCHED = YEAR(DATE)

SELECT NAME
FROM SHIPS
WHERE LAUNCHED = any(
    SELECT YEAR(DATE)
    FROM BATTLES
    WHERE COUNT(*) >= 1
);

/* Task 2 */
select distinct country,
(select count(*)
from classes c2 join ships s on c2.class = s.class
join outcomes o on s.name = o.ship
where c2.country = c.country and result = 'sunk')
from classes c
where (select count(*)
       from classes c2 join ships s  on c2.class = s.class
       where c2.country = c.country) <= 3;