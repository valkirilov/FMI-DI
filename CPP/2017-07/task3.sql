CREATE TABLE Studio(
    name VARCHAR(64) NOT NULL,
    address VARCHAR(256),
    presc VARCHAR(32),
    PRIMARY KEY (name)
);

CREATE TABLE MovieExec(
    cert VARCHAR(64) NOT NULL,
    name VARCHAR(64),
    address VARCHAR(64),
    networth INT,
    PRIMARY KEY (name)
);

CREATE TABLE Movie(
    title VARCHAR(64) NOT NULL,
    year INT(4) NOT NULL,
    length INT,
    inColor ENUM("Y", "N"),
    studioName VARCHAR(64),
    producerc VARCHAR(64),
    PRIMARY KEY(title, year),
    FOREIGN KEY (studioName) REFERENCES Studio(name)
    -- FOREIGN KEY (producerc) REFERENCES MovieExec(cert)
);

CREATE TABLE MovieStar(
    name VARCHAR(64) NOT NULL,
    address VARCHAR(256),
    gender ENUM("M", "F"),
    birthDate DATE,
    PRIMARY KEY (name)
);

CREATE TABLE StarsIn(
    movieTitle VARCHAR(64) NOT NULL,
    movieYear INT(4),
    starName VARCHAR(32),
    PRIMARY KEY (movieTitle, movieYear, starName),
    FOREIGN KEY (starName) REFERENCES MovieStar(NAME),
    FOREIGN KEY (movieTitle, movieYear) REFERENCES Movie(title, year)
);

INSERT INTO Studio(name, address, presc) VALUES
("Studio 1", "Address 1", "Cert 1"),
("Studio 2", "Address 2", "Cert 2"),
("Studio 3", "Address 3", "Cert 3");

INSERT INTO MovieExec(cert, name, address, networth) VALUES
("Cert 1", "Producer 1", "Address 1", 100),
("Cert 2", "Producer 2", "Address 2", 200),
("Cert 3", "Producer 3", "Address 3", 300);

INSERT INTO Movie(title, year, length, incolor, studioname, producerc) VALUES
("Movie 1", 1972, 10, "Y", "Studio 1", "Cert 1"),
("Movie 2", 1973, 15, "N", "Studio 2", "Cert 2"),
("Movie 3", 2002, 20, "Y", "Studio 2", "Cert 3"),
("Movie 4", 1980, 25, "Y", "Studio 2", "Cert 1"),
("Movie 5", 2002, 30, "Y", "Studio 2", "Cert 1"),
("Movie 6", 1980, 35, "Y", "Studio 2", "Cert 2"),
("Interstellar", 150, 35, "Y", "Studio 2", "Cert 2");

INSERT INTO MovieStar(name, address, gender, birthDate) VALUES
("Star 1", "Address 1", "M", 1972-08-30),
("Star 2", "Address 2", "F", 1973-08-28),
("Star 3", "Address 3", "F", 2002-09-08);

INSERT INTO StarsIn(movieTitle, movieYear, starName) VALUES
("Movie 4", 1980, "Star 1"),
("Movie 3", 2002, "Star 2"),
("Movie 3", 2002, "Star 3");

/* Task 1 */

SELECT studioname, title, year
FROM Movie m
WHERE year = (
    SELECT MAX(year)
    FROM Movie
    WHERE studioname=m.studioname
);

/* Task 2 */
SELECT name, SUM(length)
FROM MovieExec JOIN Movie ON producerc = cert
WHERE cert IN (
    SELECT DISTINCT producerc
    FROM Movie m
    WHERE m.producerc = producerc AND year=1980
)
GROUP BY name;

/* Task 3 */
SELECT starname, title, name, networth
FROM StarsIn
JOIN Movie ON movietitle=title AND movieyear=year
JOIN (
    SELECT cert, networth, name
    FROM MovieExec
    WHERE networth = (
        SELECT MAX(networth)
        FROM MovieExec
    ) t ON producerc=t.cert
______________________;


SELECT starname, title, name, networth
FROM StarsIn
JOIN Movie ON movietitle=title AND movieyear=year
JOIN (
    SELECT cert, networth, name
    FROM MovieExec
    WHERE networth = (
        SELECT MAX(networth)
        FROM MovieExec
    )) t
ON producerc = t.cert;


/* Task 4*/
SELECT name, title, year
FROM Movie JOIN MovieExec ON producerc=cert
WHERE cert = ANY (SELECT producerc
 FROM Movie
 WHERE title='Interstellar');