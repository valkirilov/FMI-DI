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
("NCLASS 2", "bc", "Germany", 3, 4, 5),
("CLASS 3", "bb", "Russia", 4, 12, 13),
("CLASS 4", "bc", "England", 4, 2, 3);


INSERT INTO `ships`(`name`, `class`, `launched`) VALUES
("SHIP 1", "CLASS 1", 1914),
("SHIP 2", "NCLASS 2", 1939),
("SHIP 3", "CLASS 3", 1939),
("SHIP 4", "CLASS 3", 1939),
("SHIP 5", "CLASS 4", 1939),
("SHIP 6", "CLASS 1", 1939),
("SHIP 7", "CLASS 1", 1939),
("SHIP 8", "CLASS 1", 1939),
("SHIP 9", "CLASS 1", 1939),
("SHIP 10", "CLASS 1", 1939),
("SHIP 11", "CLASS 1", 1939);

INSERT INTO `battles`(`name`, `date`) VALUES
("BATTLE 1", "1938-03-15 12:36:45"),
("BATTLE 2", "1939-02-05 15:42:65"),
("BATTLE 3", "1940-05-16 08:12:15"),
("BATTLE 4", "1941-05-16 08:12:15"),
("BATTLE 5", "1942-05-16 08:12:15");

INSERT INTO `outcomes`(`ship`, `battle`, `result`) VALUES
("SHIP 1", "BATTLE 1", "ok"),
("SHIP 2", "BATTLE 1", "ok"),
("SHIP 3", "BATTLE 1", "ok"),
("SHIP 1", "BATTLE 2", "sunk"),
("SHIP 2", "BATTLE 2", "sunk"),
("SHIP 5", "BATTLE 2", "sunk"),
("SHIP 1", "BATTLE 3", "damaged"),
("SHIP 2", "BATTLE 3", "damaged"),
("SHIP 3", "BATTLE 3", "damaged"),
("SHIP 5", "BATTLE 3", "damaged"),
("SHIP 3", "BATTLE 4", "damaged"),
("SHIP 6", "BATTLE 5", "sunk");

/* Task 1 */
SELECT c.class, MIN(YEAR(b.date)) AS first_battle, MAX(YEAR(b.date)) AS last_battlem COUNT(b.*) AS battles_count
FROM classes AS c
INNER JOIN ships AS s ON s.class = c.class
LEFT JOIN outcomes AS o ON o.ship = s.name
INNER JOIN battles AS b ON b.name = o.battle
WHERE c.class LIKE "N%"
GROUP BY c.class;

/* Task 2 */
SELECT o.battle
FROM outcomes AS o
INNER JOIN ships AS s ON o.ship = s.name
INNER JOIN classes AS c ON s.class = c.class
WHERE c.type = "bb"
GROUP BY o.battle
HAVING COUNT(o.ship) > (
    SELECT COUNT(*)
    FROM outcomes o2
    INNER JOIN ships AS s2 ON o2.ship = s2.name
    INNER JOIN classes AS c2 ON s2.class = c2.class
    WHERE c2.type = "bc" AND o2.battle=o.battle
)