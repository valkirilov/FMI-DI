CREATE TABLE Teams(
    tname VARCHAR(20) NOT NULL,
    tcountry VARCHAR(3) NOT NULL,
    num_tf INT UNSIGNED,
    num_stf INT UNSIGNED,
    num_yj INT UNSIGNED,
    PRIMARY KEY (tname)
);

CREATE TABLE Stages(
    snumber INT UNSIGNED NOT NULL,
    sdate DATE NOT NULL,
    km FLOAT UNSIGNED NOT NULL,
    scity VARCHAR(30) NOT NULL,
    ecity VARCHAR(30) NOT NULL,
    PRIMARY KEY (snumber)
);

CREATE TABLE Riders(
    rname VARCHAR(50) NOT NULL,
    rnum TINYINT UNSIGNED NOT NULL,
    birthdate DATE NOT NULL,
    height INT UNSIGNED NOT NULL,
    weight FLOAT UNSIGNED NOT NULL,
    rcountry VARCHAR(3) NOT NULL,
    rcity VARCHAR(20) NOT NULL,
    tname VARCHAR(20) NOT NULL,
    PRIMARY KEY (rname),
    FOREIGN KEY (tname) REFERENCES Teams(tname)
);

CREATE TABLE Tour(
    id INT UNSIGNED NOT NULL,
    snumber INT UNSIGNED NOT NULL,
    rname VARCHAR(50) NOT NULL,
    place INT UNSIGNED NOT NULL,
    points INT NOT NULL,
    ttime TIME NOT NULL,
    white BOOLEAN NOT NULL,
    yellow BOOLEAN NOT NULL,
    green BOOLEAN NOT NULL,
    PRIMARY KEY (id),
    FOREIGN KEY (snumber) REFERENCES Stages(snumber),
    FOREIGN KEY (rname) REFERENCES Riders(rname)
);