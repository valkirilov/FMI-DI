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
    FOREIGN KEY (studioName) REFERENCES Studio(name),
    FOREIGN KEY (producerc) REFERENCES MovieExec(name)
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
("STUDIO 1", "Sofia", "presc 1"),
("M STUDIO 2", "Plovdiv", "presc 2"),
("STUDIO 3", "Varna", "presc 3");

INSERT INTO MovieExec(cert, name, address, networth) VALUES
("Cert 1", "Producer 1", "Sofia", 100),
("Cert 2", "Producer 2", "Plovdiv", 200),
("Cert 3", "Producer 3", "Varna", 300);

INSERT INTO Movie(title, year, length, inColor, studioName, producerc) VALUES
("MOVIE 1", 1994, 100, "N", "STUDIO 1", "Producer 1"),
("MOVIE 2", 2000, 100, "N", "M STUDIO 2", "Producer 1"),
("MOVIE 3", 2009, 100, "Y", "M STUDIO 2", "Producer 1"),
("MOVIE 4", 1965, 100, "N", "M STUDIO 2", "Producer 2"),
("MOVIE 5", 1965, 100, "N", "M STUDIO 2", "Producer 2"),
("MOVIE 6", 1965, 100, "N", "M STUDIO 2", "Producer 3"),
("MOVIE 7", 1994, 50, "Y", "STUDIO 1", "Producer 3");

INSERT INTO MovieStar(name, address, gender, birthDate) VALUES
("STAR 1M", "Sofia", "M", 1972-08-28),
("STAR 2F", "Sofia", "F", 1973-08-30),
("STAR 3F", "Plvdiv", "F", 1973-08-30);

INSERT INTO StarsIn(movieTitle, movieYear, starName) VALUES
("MOVIE 1", 1994, "STAR 1M"),
("MOVIE 2", 2000, "STAR 2F"),
("MOVIE 3", 2009, "STAR 3F"),
("MOVIE 4", 1965, "STAR 3F");

/* Task 1 */

SELECT name, COUNT(m1.title) as movies_count, MIN(m1.year) as first_movie, MAX(m1.year) as last_movie
FROM Studio s
INNER JOIN Movie m1 ON s.name = m1.studioName
WHERE name LIKE "M%";


/* Task 2 */

SELECT name, COUNT(DISTINCT movieTitle)
FROM MovieStar ms JOIN StarsIn ON name=starName
WHERE gender="F"
HAVING COUNT(starName) >= ALL(
    SELECT COUNT(DISTINCT movieTitle)
    FROM StarsIn
    WHERE ms.name=starName
);