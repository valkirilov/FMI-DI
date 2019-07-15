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
("CLASS 3", "bb", "Russia", 4, 12, 13),
("CLASS 4", "bb", "England", 4, 2, 3);


INSERT INTO `ships`(`name`, `class`, `launched`) VALUES
("SHIP 1", "CLASS 1", 1914),
("SHIP 2", "CLASS 2", 1939),
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
("BATTLE 3", "1945-05-16 08:12:15"),
("BATTLE 4", "1945-05-16 08:12:15"),
("BATTLE 5", "1945-05-16 08:12:15");

INSERT INTO `outcomes`(`ship`, `battle`, `result`) VALUES
("SHIP 1", "BATTLE 1", "ok"),
("SHIP 2", "BATTLE 1", "ok"),
("SHIP 2", "BATTLE 2", "sunk"),
("SHIP 2", "BATTLE 3", "damaged"),
("SHIP 3", "BATTLE 4", "damaged"),
("SHIP 6", "BATTLE 5", "sunk");

/* Task 1 */
SELECT name, country
FROM ships
LEFT JOIN outcomes ON name=ship
INNER JOIN classes ON ships.class=classes.class
WHERE result IS NULL OR name NOT IN (
    SELECT DISTINCT ship
    FROM outcomes
    WHERE result="sunk"
);

/* Task 2 */
SELECT name, displacement, numguns
FROM classes c
JOIN ships s ON s.class=c.class
WHERE displacement = (
    SELECT MIN(displacement)
    FROM classes
) AND numguns = (
    SELECT MAX(numguns)
    FROM classes c1
    WHERE c1.displacement=displacement
);

/* Task 3 */
SELECT battle
FROM outcomes o1
WHERE ______________ (SELECT *
FROM outcomes o2
WHERE ________________________________________);

SELECT battle
FROM outcomes o2
GROUP BY battle
HAVING COUNT(ship) = 1

/* Task 4 */
SELECT class, COUNT(DISTINCT name)
FROM ships s JOIN outcomes o ON s.name=o.ship
WHERE result='sunk' AND class IN (
    SELECT c.class
    FROM classes c JOIN ships s ON c.class=s.class
    GROUP BY c.class
    HAVING COUNT(name)>5
)
GROUP BY class;