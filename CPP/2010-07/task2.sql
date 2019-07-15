CREATE TABLE CLASSES(
    CLASS VARCHAR(64),
    TYPE VARCHAR(2),
    COUNTRY VARCHAR(64),
    NUMGUNS INT,
    BORE INT,
    DISPLACEMENT INT,
    PRIMARY KEY (CLASS)
);

CREATE TABLE SHIPS(
    NAME VARCHAR(64),
    CLASS VARCHAR(64),
    LAUNCHED INT(4),
    PRIMARY KEY (NAME),
    FOREIGN KEY (CLASS) REFERENCES CLASSES(CLASS)
);

CREATE TABLE BATTLES(
    NAME VARCHAR(64),
    DATE DATE,
    PRIMARY KEY (NAME)
);

CREATE TABLE OUTCOMES(
    SHIP VARCHAR(64),
    BATTLE VARCHAR(64),
    RESULT VARCHAR(32),
    PRIMARY KEY (SHIP, BATTLE),
    FOREIGN KEY (SHIP) REFERENCES SHIPS(NAME),
    FOREIGN KEY (BATTLE) REFERENCES BATTLES(NAME)
);

INSERT INTO `CLASSES`(`CLASS`, `TYPE`, `COUNTRY`, `NUMGUNS`, `BORE`, `DISPLACEMENT`)
VALUES ("CLASS 1", "bb", "England", 1, 2, 3),
("CLASS 2", "bc", "Germany", 3, 4, 5),
("CLASS 3", "bb", "Russia", 4, 12, 13),
("CLASS 4", "bb", "Russia", 13, 7, 2),
("CLASS 5", "bc", "Russia", 5, 21, 8),
("CLASS 6", "bc", "America", 21, 3, 5);

INSERT INTO `SHIPS`(`NAME`, `CLASS`, `LAUNCHED`)
VALUES ("SHIP 1", "CLASS 1", 1914),
("SHIP 2", "CLASS 1", 1938),
("SHIP 3", "CLASS 2", 1944),
("SHIP 4", "CLASS 3", 1944),
("SHIP 5", "CLASS 4", 1944);

INSERT INTO `BATTLES`(`NAME`, `DATE`)
VALUES ("BATTLE 1", "1938-03-15 12:36:45"),
("BATTLE 2", "1939-02-5 15:42:65"),
("BATTLE 3", "1945-05-16 08:12:15"),
("BATTLE 4", "1945-05-16 08:12:15"),
("BATTLE 5", "1945-05-16 08:12:15"),
("BATTLE 6", "1945-05-16 08:12:15"),
("BATTLE 7", "1945-05-16 08:12:15"),
("BATTLE 8", "1945-05-16 08:12:15"),
("BATTLE 9", "1945-05-16 08:12:15");

INSERT INTO `OUTCOMES`(`SHIP`, `BATTLE`, `RESULT`)
VALUES ("SHIP 1", "BATTLE 1", "ok"),
("SHIP 2", "BATTLE 2", "sunk"),
("SHIP 2", "BATTLE 3", "damaged"),
("SHIP 5", "BATTLE 4", "damaged"),
("SHIP 5", "BATTLE 5", "damaged"),
("SHIP 5", "BATTLE 6", "damaged"),
("SHIP 4", "BATTLE 7", "damaged"),
("SHIP 4", "BATTLE 8", "damaged"),
("SHIP 4", "BATTLE 9", "damaged");

/* Ex. 1 */
SELECT DISTINCT COUNTRY
FROM CLASSES
WHERE NUMGUNS > 10 AND COUNTRY IN
(SELECT COUNTRY FROM CLASSES WHERE NUMGUNS < 6)

/** Ex. 2 */
SELECT DISTINCT COUNTRY, COUNT(O.BATTLE) AS NUM_BATTLES
FROM CLASSES C
LEFT JOIN SHIPS S ON C.CLASS=S.CLASS
LEFT JOIN OUTCOMES O ON S.NAME=O.SHIP
GROUP BY COUNTRY
HAVING COUNT(O.BATTLE)<=3

/* wrong */
SELECT COUNTRY, COUNT(DISTINCT BATTLE) AS NUM_BATTLES
FROM CLASSES AS C, SHIPS AS S, OUTCOMES AS O
WHERE C.CLASS=S.CLASS AND S.NAME=O.SHIP
GROUP BY COUNTRY
HAVING COUNT(DISTINCT BATTLE) < 3;

SELECT C.COUNTRY, COUNT(O.BATTLE) AS NUM_BATTLES
FROM CLASSES AS C
INNER JOIN SHIPS AS S ON C.CLASS=S.CLASS
LEFT OUTER JOIN OUTCOMES AS O ON S.NAME=O.SHIP
WHERE COUNT(O.BATTLE) <= 2;