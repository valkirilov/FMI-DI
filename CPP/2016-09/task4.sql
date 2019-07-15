CREATE TABLE classes(
    class VARCHAR(64) NOT NULL,
    type ENUM("bb", "bc") NOT NULL,
    country VARCHAR(64) NOT NULL,
    numguns INT,
    bore INT,
    displacement INT,
    PRIMARY KEY (class)
);

CREATE TABLE ships(
    name VARCHAR(64) NOT NULL,
    class VARCHAR(64) NOT NULL,
    launched INT(4),
    PRIMARY KEY (name),
    FOREIGN KEY (class) REFERENCES classes(class)
);

CREATE TABLE battles(
    name VARCHAR(64) NOT NULL,
    date DATE NOT NULL,
    PRIMARY KEY (name)
);

CREATE TABLE outcomes(
    ship VARCHAR(64) NOT NULL,
    battle VARCHAR(64) NOT NULL,
    result ENUM("sunk", "damaged", "ok") NOT NULL,
    PRIMARY KEY (ship, battle),
    FOREIGN KEY (ship) REFERENCES ships(name),
    FOREIGN KEY (battle) REFERENCES battles(name)
);

INSERT INTO `classes`(`class`, `type`, `country`, `numguns`, `bore`, `displacement`) VALUES
("CLASS 1", "bb", "England", 1, 2, 3),
("CLASS 2", "bc", "Germany", 3, 4, 5),
("CLASS 3", "bb", "Russia", 4, 12, 13);

INSERT INTO `ships`(`name`, `class`, `launched`) VALUES
("SHIP 1", "CLASS 1", 1914),
("SHIP 2", "CLASS 2", 1939),
("SHIP 3", "CLASS 3", 1939),
("SHIP 4", "CLASS 3", 1939);

INSERT INTO `battles`(`name`, `date`) VALUES
("Coral Sea", "1938-03-15 12:36:45"),
("BATTLE 2", "1939-02-05 15:42:65"),
("BATTLE 3", "1945-05-16 08:12:15"),
("BATTLE 4", "1945-05-16 08:12:15"),
("BATTLE 5", "1945-05-16 08:12:15"),
("BATTLE 6", "1945-05-16 08:12:15");

INSERT INTO `outcomes`(`ship`, `battle`, `result`) VALUES
("SHIP 2", "Coral Sea", "ok"),
("SHIP 3", "BATTLE 2", "sunk"),
("SHIP 2", "BATTLE 3", "sunk"),
("SHIP 3", "BATTLE 3", "sunk"),
("SHIP 4", "BATTLE 3", "sunk"),
("SHIP 2", "BATTLE 5", "damaged"),
("SHIP 2", "BATTLE 6", "damaged"),
("SHIP 3", "BATTLE 6", "ok");

/* Task 1 */
SELECT DISTINCT c.country, (SELECT COUNT(o.result)
FROM classes c1 JOIN ships s
ON c1.class=s.class
JOIN outcomes o ON s.name=o.ship
WHERE result='sunk'
AND c1.country=c.country)
FROM classes c;

SELECT c.country , COUNT(o.result)
FROM classes c left join ships s ON c.class=s.class
LEFT JOIN outcomes o ON s.name=o.ship
WHERE result='sunk' OR result IS NOT NULL
GROUP BY c.country;

/* Task 2*/
SELECT DISTINCT battle
FROM outcomes o1
WHERE
(SELECT COUNT(DISTINCT country)
FROM outcomes o,ships s,classes c
WHERE o.ship=s.name AND s.class=c.class AND battle=o1.battle)
>
(SELECT count(DISTINCT country)
FROM outcomes o,ships s,classes c
WHERE o.ship=s.name AND s.class=c.class AND battle='Coral Sea')

SELECT DISTINCT battle
FROM outcomes o, ships s, classes c
Where o.ship=s.name AND s.class=c.class
GROUP BY battle
HAVING COUNT(DISTINCT country)>(SELECT COUNT(country)
FROM outcomes o, classes c, ships s
WHERE ship=name AND s.class=c.class
AND battle='Coral Sea');