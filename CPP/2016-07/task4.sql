CREATE TABLE Studio(
    name VARCHAR(64) NOT NULL,
    address VARCHAR(256),
    presc VARCHAR(32),
    PRIMARY KEY (name)
);

CREATE TABLE MovieExec(
    name VARCHAR(64) NOT NULL,
    address VARCHAR(64),
    networth INT,
    birthdate DATE,
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
("STUDIO 2", "Plovdiv", "presc 2"),
("STUDIO 3", "Varna", "presc 3");

INSERT INTO MovieExec(name, address, networth, birthdate) VALUES
("Producer 1", "Sofia", 100,1972-08-28),
("Producer 2", "Plovdiv", 200, 1972-08-30),
("Producer 3", "Varna", 300, 1972-09-08);

INSERT INTO Movie(title, year, length, inColor, studioName, producerc) VALUES
("Pretty Woman", 1994, 100, "N", "STUDIO 1", "Producer 1"),
("MOVIE 2", 2000, 100, "N", "STUDIO 2", "Producer 1"),
("MOVIE 3", 2009, 100, "Y", "STUDIO 2", "Producer 1"),
("MOVIE 4", 1965, 100, "N", "STUDIO 2", "Producer 2"),
("MOVIE 5", 1965, 100, "N", "STUDIO 2", "Producer 2"),
("MOVIE 6", 1965, 100, "N", "STUDIO 2", "Producer 3"),
("MOVIE 7", 1994, 50, "Y", "STUDIO 1", "Producer 3");

INSERT INTO MovieStar(name, address, gender, birthDate) VALUES
("STAR 1", "Sofia", "M", 1972-08-28),
("STAR 2a", "Sofia", "F", 1973-08-30),
("STAR 3", "Plvdiv", "F", 1973-08-30),
("STAR 4", "Varna", "F", 1973-08-30);

INSERT INTO StarsIn(movieTitle, movieYear, starName) VALUES
("Pretty Woman", 1994, "STAR 1"),
("MOVIE 2", 2000, "STAR 1"),
("MOVIE 3", 2009, "STAR 2a"),
("MOVIE 4", 1965, "STAR 2a"),
("Pretty Woman", 1994, "STAR 3"),
("MOVIE 2", 2000, "STAR 3"),
("MOVIE 3", 2009, "STAR 3"),
("MOVIE 4", 1965, "STAR 3"),
("MOVIE 5", 1965, "STAR 3"),
("MOVIE 6", 1965, "STAR 3");

/* Task 1 */
SELECT studioName, starName, COUNT(DISTINCT starName)
FROM Movie m JOIN StarsIn ON title=movieTitle AND year=movieYear
WHERE studioName IS NOT NULL
GROUP BY m.studioName,starName
HAVING COUNT(starName)>=ALL(SELECT COUNT(DISTINCT starName)
FROM Movie,StarsIn
WHERE title=movieTitle
AND year=movieYear
AND studioName=m.studioName
GROUP BY studioName,starName);