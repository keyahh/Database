Main commands:
CREATE TABLE <table name> <(columns list)>
CREATE TABLE testTable (c1,c2,c3)

INSERT INTO <table name> <(columns list)> VALUES <(values list)>
INSERT INTO testTable (c1,c2) VALUES (ddfo,ewqop)

SELECT <(columns list)> FROM <table name>
SELECT (c1,c2) FROM testTable

DELETE FROM <table name> WHERE <column name><comparison operator><value>
DELETE FROM testTable WHERE c1>100

Quality of life features:
Press tab to autocomplete to the top suggestion
Press UP/DOWN arrow keys to go back to previously entered commands