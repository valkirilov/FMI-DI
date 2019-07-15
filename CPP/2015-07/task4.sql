CREATE TABLE Studio(
    name VARCHAR(64),
    address VARCHAR(256),
    PRIMARY KEY (name)
);

CREATE TABLE Movie(
    title VARCHAR(64),
    year INT(4),
    length INT,
    inColor ENUM("Y", "N"),
    studioName VARCHAR(64),
    PRIMARY KEY(title, year),
    FOREIGN KEY (studioName) REFERENCES Studio(name)
);

CREATE TABLE MovieStar(
    name VARCHAR(64),
    address VARCHAR(256),
    gender ENUM("M", "F"),
    birthDate DATE,
    PRIMARY KEY (name)
);

CREATE TABLE StarsIn(
    movieTitle VARCHAR(64),
    movieYear INT(4),
    starName VARCHAR(32),
    PRIMARY KEY (movieTitle, movieYear, starName),
    FOREIGN KEY (starName) REFERENCES MovieStar(NAME),
    FOREIGN KEY (movieTitle, movieYear) REFERENCES Movie(title, year)
);

INSERT INTO Studio(name, address) VALUES
("STUDIO 1", "ADDRESS 1"),
("STUDIO 2", "ADDRESS 2"),
("STUDIO 3", "ADDRESS 3");

INSERT INTO Movie(title, year, length, inColor, studioName) VALUES
("MOVIE 1", 1994, 100, "Y", "STUDIO 1"),
("MOVIE 2", 2000, 100, "N", "STUDIO 2"),
("MOVIE 3", 2009, 100, "Y", "STUDIO 2"),
("MOVIE 4", 1965, 100, "N", "STUDIO 2"),
("MOVIE 5", 1965, 100, "N", "STUDIO 2"),
("MOVIE 6", 1965, 100, "N", "STUDIO 2");

INSERT INTO MovieStar(name, address, gender, birthDate) VALUES
("STAR 1", "ADDRESS 1", "M", 1972-08-28),
("STAR 2a", "ADDRESS 1", "F", 1973-08-30),
("STAR 3", "ADDRESS 1", "F", 1973-08-30),
("STAR 4", "ADDRESS 1", "F", 1973-08-30);

INSERT INTO StarsIn(movieTitle, movieYear, starName) VALUES
("MOVIE 1", 1994, "STAR 1"),
("MOVIE 2", 2000, "STAR 1"),
("MOVIE 3", 2009, "STAR 2a"),
("MOVIE 4", 1965, "STAR 2a"),
("MOVIE 1", 1994, "STAR 3"),
("MOVIE 2", 2000, "STAR 3"),
("MOVIE 3", 2009, "STAR 3"),
("MOVIE 4", 1965, "STAR 3"),
("MOVIE 5", 1965, "STAR 3"),
("MOVIE 6", 1965, "STAR 3");

/** Task 1 **/
SELECT MovieStar.name
FROM MovieStar
WHERE NOT (name LIKE '%a')
AND name IN (SELECT starName
FROM StarsIn
JOIN Movie ON movieTitle = title AND movieYear = year
WHERE inColor = 'y' OR inColor = 'n');

/* Task 2 */
SELECT name, YEAR(birthdate), COUNT(DISTINCT studioName)
FROM MovieStar
LEFT OUTER JOIN StarsIn ON name = starname
LEFT JOIN Movie ON movieTitle = title AND movieYear = year
GROUP BY name
HAVING COUNT(title) <= 5;
