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
("STUDIO 1", "Sofia"),
("STUDIO 2", "Plovdiv"),
("STUDIO 3", "Varna");

INSERT INTO Movie(title, year, length, inColor, studioName) VALUES
("MOVIE 1", 1994, 100, "N", "STUDIO 1"),
("MOVIE 2", 2000, 100, "N", "STUDIO 2"),
("MOVIE 3", 2009, 100, "Y", "STUDIO 2"),
("MOVIE 4", 1965, 100, "N", "STUDIO 2"),
("MOVIE 5", 1965, 100, "N", "STUDIO 2"),
("MOVIE 6", 1965, 100, "N", "STUDIO 2"),
("MOVIE 7", 1994, 50, "Y", "STUDIO 1");

INSERT INTO MovieStar(name, address, gender, birthDate) VALUES
("STAR 1", "Sofia", "M", 1972-08-28),
("STAR 2a", "Sofia", "F", 1973-08-30),
("STAR 3", "Plvdiv", "F", 1973-08-30),
("STAR 4", "Varna", "F", 1973-08-30);

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

/* Task 1 */
SELECT name, address
FROM MovieStar MS
WHERE gender = 'F'
ORDER BY address
UNION ALL
SELECT name, address
FROM Studio
WHERE address LIKE '%Sofia%'
ORDER BY address;