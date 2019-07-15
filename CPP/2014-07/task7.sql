
CREATE TABLE Groups(
    gname CHAR NOT NULL,
    fname VARCHAR(20) NOT NULL,
    sname VARCHAR(20) NOT NULL,
    PRIMARY KEY (gname)
);

CREATE TABLE Teams(
    country VARCHAR(20) NOT NULL,
    gname CHAR NOT NULL,
    num_wc INT(2) UNSIGNED NOT NULL,
    PRIMARY KEY (country),
    FOREIGN KEY (gname) REFERENCES Groups(gname)
);

CREATE TABLE Players(
    pname VARCHAR(50) NOT NULL,
    team VARCHAR(20) NOT NULL,
    num_player INT(2) UNSIGNED NOT NULL,
    num_goals INT UNSIGNED NOT NULL,
    PRIMARY KEY (pname),
    CONSTRAINT num_player_range CHECK (num_player BETWEEN 1 AND 22)
);


CREATE TABLE Matches(
    mnumber INT UNSIGNED NOT NULL,
    tstage VARCHAR(8) NOT NULL,
    stage VARCHAR(3),
    team_host VARCHAR(20) NOT NULL,
    team_guest VARCHAR(20) NOT NULL,
    result CHAR NOT NULL,
    scores VARCHAR(5) NOT NULL,
    date DATE NOT NULL,
    time TIME NOT NULL,
    PRIMARY KEY (mnumber),
    FOREIGN KEY (team_host) REFERENCES Teams(country),
    FOREIGN KEY (team_guest) REFERENCES Teams(country)
);

ALTER TABLE Groups ADD CONSTRAINT FOREIGN KEY (fname) REFERENCES Teams(country);
ALTER TABLE Groups ADD CONSTRAINT FOREIGN KEY (sname) REFERENCES Teams(country);
ALTER TABLE Teams ADD CONSTRAINT FOREIGN KEY (gname) REFERENCES Groups(gname);
ALTER TABLE Players ADD CONSTRAINT FOREIGN KEY (team) REFERENCES Teams(country);
