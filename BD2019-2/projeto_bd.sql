
CREATE TABLE Plano(
IdPlano integer,
Tipo varchar(20),
Preço double,
PRIMARY KEY (IdPlano)
);
CREATE TABLE Usuario(
Username varchar(16),
NomeUsuario varchar(50),
NumSeguidores integer,
Seguindo integer,
Plano integer,
PRIMARY KEY (Username),
FOREIGN KEY (Plano) REFERENCES Plano(IdPlano)
);
CREATE TABLE Genero(
IdGenero integer,
Genero varchar(20),
PRIMARY KEY (IdGenero)
);
CREATE TABLE Musica(
IdMusica integer,
NomeMusica varchar(100),
Duracao integer,
DataLancamento varchar(10),
IdGenero integer,
PRIMARY KEY (IdMusica),
FOREIGN KEY (IdGenero) REFERENCES Genero(IdGenero)
);
CREATE TABLE Album(
IdAlbum integer,
NomeAlbum varchar(100),
DataLancamento varchar(10),
PRIMARY KEY (IdAlbum)
);
CREATE TABLE Gravadora(
IdGravadora integer,
NomeGravadora varchar(50),
PRIMARY KEY (IdGravadora)
);
CREATE TABLE Artista(
IdArtista integer,
NomeArtista varchar(50),
Seguidores integer,
OuvintesMensais integer,
IdGravadora integer,
PRIMARY KEY (IdArtista),
FOREIGN KEY (IdGravadora) REFERENCES Gravadora(IdGravadora)
);

CREATE TABLE SituacaoPlaylist(
Situacao varchar(50),
PRIMARY KEY (Situacao)
);

CREATE TABLE Playlist(
IdPlaylist integer,
NomePlaylist varchar(50),
NumSeguidores integer,
Duracao integer,
UsernameCriador varchar(16),
Situacao varchar(50),
PRIMARY KEY (IdPlaylist),
FOREIGN KEY (UsernameCriador) REFERENCES Usuario(Username),
FOREIGN KEY (Situacao) REFERENCES SituacaoPlaylist(Situacao)
);
CREATE TABLE Produtor(
IdProdutor integer,
NomeProdutor varchar(50),
PRIMARY KEY (IdProdutor)
);
CREATE TABLE Compositor(
IdCompositor integer,
NomeCompositor varchar(50),
PRIMARY KEY (IdCompositor)
);


CREATE TABLE FaixaDeAlbum(
IdAlbum integer,
IdMusica integer,
PRIMARY KEY (IdAlbum, IdMusica),
FOREIGN KEY (IdAlbum) REFERENCES Album(IdAlbum),
FOREIGN KEY (IdMusica) REFERENCES Musica(IdMusica)
);
CREATE TABLE ProducaoMusica(
IdProdutor integer,
IdMusica integer,
PRIMARY KEY (IdProdutor, IdMusica),
FOREIGN KEY (IdProdutor) REFERENCES Produtor(IdProdutor),
FOREIGN KEY (IdMusica) REFERENCES Musica(IdMusica)
);
CREATE TABLE ComposicaoMusica(
IdCompositor integer,
IdMusica integer,
PRIMARY KEY (IdCompositor, IdMusica),
FOREIGN KEY (IdCompositor) REFERENCES Compositor(IdCompositor),
FOREIGN KEY (IdMusica) REFERENCES Musica(IdMusica)
);
CREATE TABLE ProducaoAlbum(
IdProdutor integer,
IdAlbum integer,
PRIMARY KEY (IdProdutor, IdAlbum),
FOREIGN KEY (IdProdutor) REFERENCES Produtor(IdProdutor),
FOREIGN KEY (IdAlbum) REFERENCES Album(IdAlbum)
);
CREATE TABLE FaixaDePlaylist(
IdPlaylist integer,
IdMusica integer,
PRIMARY KEY (IdPlaylist, IdMusica),
FOREIGN KEY (IdPlaylist) REFERENCES Playlist(IdPlaylist),
FOREIGN KEY (IdMusica) REFERENCES Musica(IdMusica)
);


-- Inserção de dados no BD

-- Plano

INSERT INTO Plano VALUES (1,'Free', 25.00);
INSERT INTO Plano VALUES (2,'Individual', 25.00);
INSERT INTO Plano VALUES (3,'Casal', 40.00);
INSERT INTO Plano VALUES (4,'Familia',50.00);


-- Usuario

INSERT INTO Usuario VALUES ('Igorfn','Igor Fonseca',7,4,1);
INSERT INTO Usuario VALUES ('AmandaG','Amanda Goulart',25,20,4);
INSERT INTO Usuario VALUES ('VictorH','Victor Hugo',15,8,2);
INSERT INTO Usuario VALUES ('JoãoPH','João Pedro',27,6,1);
INSERT INTO Usuario VALUES ('HansAr','Hans Araujo',41,58,4);
INSERT INTO Usuario VALUES ('AlissonFG','Alisson Felipe',11,9,2);
INSERT INTO Usuario VALUES ('FelipeLB','Felipe Léo',33,27,4);
INSERT INTO Usuario VALUES ('LarissaRib','Larissa Ribeiro',14,15,3);
INSERT INTO Usuario VALUES ('FabianoAu','Fabiano Augusto',11,24,3);
INSERT INTO Usuario VALUES ('KamillaGd','Kamilla Galdino',48,34,2);

-- Genero

INSERT INTO Genero VALUES (1,'Axé');
INSERT INTO Genero VALUES (2,'Blues');
INSERT INTO Genero VALUES (3,'Country');
INSERT INTO Genero VALUES (4,'Eletrônica');
INSERT INTO Genero VALUES (5,'Forró');
INSERT INTO Genero VALUES (6,'Funk');
INSERT INTO Genero VALUES (7,'Gospel');
INSERT INTO Genero VALUES (8,'Hip Hop');
INSERT INTO Genero VALUES (9,'Pop');
INSERT INTO Genero VALUES (10,'Rock');


-- Musica

INSERT INTO Musica VALUES (1,'Eva',450,'1997/11/10',1);
INSERT INTO Musica VALUES (2,'Sorte Grande',350,'2003/10/01',1);
INSERT INTO Musica VALUES (3,'Vem, Meu Amor',430,'1997/12/02',1);
INSERT INTO Musica VALUES (4,'Mannish Boy',530,'1930/07/08',2);
INSERT INTO Musica VALUES (5,'Mannish Boy',580,'1947/11/09',2);
INSERT INTO Musica VALUES (6,'Dust My Broom',373,'1952/09/05',2);
INSERT INTO Musica VALUES (7,'Need You Now',370,'2010/10/11',3);
INSERT INTO Musica VALUES (8,'Before He Cheats',290,'2005/12/12',3);
INSERT INTO Musica VALUES (9,'Never Let Me Go',270,'2017/18/03',4);
INSERT INTO Musica VALUES (10,'Wake Me Up',370,'2013/18/08',4);
INSERT INTO Musica VALUES (11,'My Way',255,'2016/22/04',4);
INSERT INTO Musica VALUES (12,'Acabou Acabou',370,'2017/11/07',5);
INSERT INTO Musica VALUES (13,'Disse Adeus',470,'1999/28/07',5);
INSERT INTO Musica VALUES (14,'Onde o Sonho Mora',420,'1996/28/11',5);
INSERT INTO Musica VALUES (15,'Vai Malandra',220,'2017/22/11',6);
INSERT INTO Musica VALUES (16,'Favela Chegou',260,'2019/12/12',6);
INSERT INTO Musica VALUES (17,'Rabiola',245,'2017/12/04',6);
INSERT INTO Musica VALUES (18,'Raridade',320,'2013/28/12',7);
INSERT INTO Musica VALUES (19,'Eu Navegarei',360,'2018/24/11',7);
INSERT INTO Musica VALUES (20,'In da Club',345,'20013/17/03',8);
INSERT INTO Musica VALUES (21,'It’s Murda',320,'1999/22/12',8);
INSERT INTO Musica VALUES (22,'Lose Yourself',295,'2002/18/06',8);
INSERT INTO Musica VALUES (23,'Shape of You',340,'2017/21/07',9);
INSERT INTO Musica VALUES (24,'Thunder',270,'2017/26/01',9);
INSERT INTO Musica VALUES (25,'November Rain',510,'1987/20/09',10);
INSERT INTO Musica VALUES (26,'Smoke on the Water',370,'1996/14/04',10);
INSERT INTO Musica VALUES (27,'Starway to Heaven',320,'1971/25/11',10);
INSERT INTO Musica VALUES (28,'Wonderwall',330,'1995/28/09',10);

--  album

INSERT INTO Album VALUES (1,'Envolve','1995/28/09');
INSERT INTO Album VALUES (2,'Crossroad','1998/18/07');
INSERT INTO Album VALUES (3,'Origins','1990/15/01');
INSERT INTO Album VALUES (4,'O tempo é agora','2005/20/07');
INSERT INTO Album VALUES (5,'Renovo','1999/08/01');
INSERT INTO Album VALUES (6,'By the Way','2007/28/09');
INSERT INTO Album VALUES (7,'Kisses','1991/27/09');
INSERT INTO Album VALUES (8,'Ten','2005/18/6');
INSERT INTO Album VALUES (9,'Im not Dead','2015/15/02');
INSERT INTO Album VALUES (10,'Sinceridade','2009/01/06');


-- Gravadora

INSERT INTO Gravadora VALUES (1,'Byo Records');
INSERT INTO Gravadora VALUES (2,'RCA Records');
INSERT INTO Gravadora VALUES (3,'Roc Nation');
INSERT INTO Gravadora VALUES (4,'G-unit');
INSERT INTO Gravadora VALUES (5,'GOOD Music');


-- Artista (IdArtista,NomeArtista,Seguidores,OuvintesMensais,IdGravadora)

INSERT INTO Artista VALUES (1,'Ed Sheeran',100,29,1);
INSERT INTO Artista VALUES (2,'Lady Gaga',28,25,1);
INSERT INTO Artista VALUES (3,'Zezé Di Camargo e Luciano',55,29,2);
INSERT INTO Artista VALUES (4,'The Beatles',141,98,2);
INSERT INTO Artista VALUES (5,'Ed Sheeran',80,25,2);
INSERT INTO Artista VALUES (6,'Roberto Carlos',90,29,3);
INSERT INTO Artista VALUES (7,'Anita',119,29,3);
INSERT INTO Artista VALUES (8,'Luan Santana',112,22,4);
INSERT INTO Artista VALUES (9,'MC Brinquedo',115,24,4);
INSERT INTO Artista VALUES (10,'Tim Maia',129,28,5);

-- SituacaoPlaylist (Situacao)

INSERT INTO SituacaoPlaylist VALUES ('Privado');
INSERT INTO SituacaoPlaylist VALUES ('Publico');
INSERT INTO SituacaoPlaylist VALUES ('Compartilhado');


-- Playlist (IdPlaylist,NomePlaylist,NumSeguidores,Duracao,UsernameCriador,Situacao)

INSERT INTO Playlist VALUES (1,'Sofrencia',55,590,'Igorfn','Privado');
INSERT INTO Playlist VALUES (2,'Popzera',40,650,'AmandaG','Publico');
INSERT INTO Playlist VALUES (3,'As Melhores',60,950,'VictorH','Compartilhado');
INSERT INTO Playlist VALUES (4,'Coletânia Clássica',59,550,'VictorH','Compartilhado');
INSERT INTO Playlist VALUES (5,'Atualidade',49,750,'HansAr','Publico');

-- Produtor(IdProdutor,NomeProdutor)
INSERT INTO Produtor VALUES (1,'Eddie Krammer');
INSERT INTO Produtor VALUES (2,'Al Schmitt');
INSERT INTO Produtor VALUES (3,'Terry Date');
INSERT INTO Produtor VALUES (4,'Andrew Scheps');
INSERT INTO Produtor VALUES (5,'George Martin');
INSERT INTO Produtor VALUES (6,'Quincy Jones');
INSERT INTO Produtor VALUES (7,'Rick Rubin');
INSERT INTO Produtor VALUES (8,'Phil Spector');
INSERT INTO Produtor VALUES (9,'Steve Albini');
INSERT INTO Produtor VALUES (10,'Brian Wilson');


-- Compositor (idCompositor,NomeCompositor)
INSERT INTO Compositor VALUES (1, 'Heitor Villa-Lobos');
INSERT INTO Compositor VALUES (2, 'Pixinguinha');
INSERT INTO Compositor VALUES (3, 'Ary Barroso');
INSERT INTO Compositor VALUES (4, 'Ezra Pound');
INSERT INTO Compositor VALUES (5, 'Walter Piston');
INSERT INTO Compositor VALUES (6, 'John Williams');
INSERT INTO Compositor VALUES (7, 'Joan La Barbara');
INSERT INTO Compositor VALUES (8, 'Hector Berlioz');
INSERT INTO Compositor VALUES (9, 'Peter Gast');
INSERT INTO Compositor VALUES (10, 'Antonio Salieri');



-- ProducaoAlbum ()
INSERT INTO ProducaoAlbum VALUES (1, 10);
INSERT INTO ProducaoAlbum VALUES (2, 9);
INSERT INTO ProducaoAlbum VALUES (3, 8);
INSERT INTO ProducaoAlbum VALUES (4, 7);
INSERT INTO ProducaoAlbum VALUES (5, 6);
INSERT INTO ProducaoAlbum VALUES (6, 5);
INSERT INTO ProducaoAlbum VALUES (7, 4);
INSERT INTO ProducaoAlbum VALUES (8, 3);
INSERT INTO ProducaoAlbum VALUES (9, 2);
INSERT INTO ProducaoAlbum VALUES (10, 1);

-- FaixaDeAlbum(IdAlbum,IdMusica)

INSERT INTO FaixaDeAlbum VALUES (1, 1);
INSERT INTO FaixaDeAlbum VALUES (2, 2);
INSERT INTO FaixaDeAlbum VALUES (3, 3);
INSERT INTO FaixaDeAlbum VALUES (4, 4);
INSERT INTO FaixaDeAlbum VALUES (5, 5);
INSERT INTO FaixaDeAlbum VALUES (6, 6);
INSERT INTO FaixaDeAlbum VALUES (7, 7);
INSERT INTO FaixaDeAlbum VALUES (8, 8);
INSERT INTO FaixaDeAlbum VALUES (9, 9);
INSERT INTO FaixaDeAlbum VALUES (10,10);
INSERT INTO FaixaDeAlbum VALUES (1,11);
INSERT INTO FaixaDeAlbum VALUES (2,12);
INSERT INTO FaixaDeAlbum VALUES (3,13);
INSERT INTO FaixaDeAlbum VALUES (4,14);
INSERT INTO FaixaDeAlbum VALUES (5,15);
INSERT INTO FaixaDeAlbum VALUES (6,16);
INSERT INTO FaixaDeAlbum VALUES (7,17);
INSERT INTO FaixaDeAlbum VALUES (8,18);
INSERT INTO FaixaDeAlbum VALUES (9,19);
INSERT INTO FaixaDeAlbum VALUES (10,20);
INSERT INTO FaixaDeAlbum VALUES (1,21);
INSERT INTO FaixaDeAlbum VALUES (2,22);
INSERT INTO FaixaDeAlbum VALUES (3,23);
INSERT INTO FaixaDeAlbum VALUES (4,24);
INSERT INTO FaixaDeAlbum VALUES (5,25);
INSERT INTO FaixaDeAlbum VALUES (6,26);
INSERT INTO FaixaDeAlbum VALUES (7,27);
INSERT INTO FaixaDeAlbum VALUES (8,28);



-- ProducaoMusica(IdProdutor,IdMusica)

INSERT INTO ProducaoMusica VALUES (8, 1);
INSERT INTO ProducaoMusica VALUES (2, 2);
INSERT INTO ProducaoMusica VALUES (3, 3);
INSERT INTO ProducaoMusica VALUES (4, 4);
INSERT INTO ProducaoMusica VALUES (5, 5);
INSERT INTO ProducaoMusica VALUES (6, 6);
INSERT INTO ProducaoMusica VALUES (5, 7);
INSERT INTO ProducaoMusica VALUES (8, 8);
INSERT INTO ProducaoMusica VALUES (8, 9);
INSERT INTO ProducaoMusica VALUES (10,10);
INSERT INTO ProducaoMusica VALUES (1,11);
INSERT INTO ProducaoMusica VALUES (5,12);
INSERT INTO ProducaoMusica VALUES (3,13);
INSERT INTO ProducaoMusica VALUES (4,14);
INSERT INTO ProducaoMusica VALUES (5,15);
INSERT INTO ProducaoMusica VALUES (8,16);
INSERT INTO ProducaoMusica VALUES (7,17);
INSERT INTO ProducaoMusica VALUES (1,18);
INSERT INTO ProducaoMusica VALUES (9,19);
INSERT INTO ProducaoMusica VALUES (3,20);
INSERT INTO ProducaoMusica VALUES (1,21);
INSERT INTO ProducaoMusica VALUES (2,22);
INSERT INTO ProducaoMusica VALUES (3,23);
INSERT INTO ProducaoMusica VALUES (8,24);
INSERT INTO ProducaoMusica VALUES (1,25);
INSERT INTO ProducaoMusica VALUES (6,26);
INSERT INTO ProducaoMusica VALUES (7,27);
INSERT INTO ProducaoMusica VALUES (1,28);

-- ComposicaoMusica(IdCompositor,IdMusica)
INSERT INTO ComposicaoMusica VALUES (1, 1);
INSERT INTO ComposicaoMusica VALUES (2, 2);
INSERT INTO ComposicaoMusica VALUES (3, 3);
INSERT INTO ComposicaoMusica VALUES (4, 4);
INSERT INTO ComposicaoMusica VALUES (5, 5);
INSERT INTO ComposicaoMusica VALUES (2, 6);
INSERT INTO ComposicaoMusica VALUES (7, 7);
INSERT INTO ComposicaoMusica VALUES (8, 8);
INSERT INTO ComposicaoMusica VALUES (8, 9);
INSERT INTO ComposicaoMusica VALUES (10,10);
INSERT INTO ComposicaoMusica VALUES (5,11);
INSERT INTO ComposicaoMusica VALUES (2,12);
INSERT INTO ComposicaoMusica VALUES (3,13);
INSERT INTO ComposicaoMusica VALUES (2,14);
INSERT INTO ComposicaoMusica VALUES (2,15);
INSERT INTO ComposicaoMusica VALUES (9,16);
INSERT INTO ComposicaoMusica VALUES (1,17);
INSERT INTO ComposicaoMusica VALUES (1,18);
INSERT INTO ComposicaoMusica VALUES (9,19);
INSERT INTO ComposicaoMusica VALUES (10,20);
INSERT INTO ComposicaoMusica VALUES (1,21);
INSERT INTO ComposicaoMusica VALUES (1,22);
INSERT INTO ComposicaoMusica VALUES (3,23);
INSERT INTO ComposicaoMusica VALUES (3,24);
INSERT INTO ComposicaoMusica VALUES (5,25);
INSERT INTO ComposicaoMusica VALUES (6,26);
INSERT INTO ComposicaoMusica VALUES (8,27);
INSERT INTO ComposicaoMusica VALUES (8,28);

-- FaixaDePlaylist (IdPlaylist,IdMusica)
INSERT INTO FaixaDePlaylist VALUES (1,1);
INSERT INTO FaixaDePlaylist VALUES (1,2);
INSERT INTO FaixaDePlaylist VALUES (1,3);
INSERT INTO FaixaDePlaylist VALUES (2,4);
INSERT INTO FaixaDePlaylist VALUES (2,5);
INSERT INTO FaixaDePlaylist VALUES (5,6);
INSERT INTO FaixaDePlaylist VALUES (4,7);
INSERT INTO FaixaDePlaylist VALUES (4,8);
INSERT INTO FaixaDePlaylist VALUES (3,9);
INSERT INTO FaixaDePlaylist VALUES (3,10);
INSERT INTO FaixaDePlaylist VALUES (3,11);
INSERT INTO FaixaDePlaylist VALUES (3,12);
INSERT INTO FaixaDePlaylist VALUES (5,13);
INSERT INTO FaixaDePlaylist VALUES (1,14);
INSERT INTO FaixaDePlaylist VALUES (1,15);
INSERT INTO FaixaDePlaylist VALUES (1,16);
INSERT INTO FaixaDePlaylist VALUES (4,17);
INSERT INTO FaixaDePlaylist VALUES (2,18);
INSERT INTO FaixaDePlaylist VALUES (2,19);
INSERT INTO FaixaDePlaylist VALUES (1,20);
INSERT INTO FaixaDePlaylist VALUES (2,21);
INSERT INTO FaixaDePlaylist VALUES (1,22);
INSERT INTO FaixaDePlaylist VALUES (5,23);
INSERT INTO FaixaDePlaylist VALUES (1,24);
INSERT INTO FaixaDePlaylist VALUES (4,25);
INSERT INTO FaixaDePlaylist VALUES (3,26);
INSERT INTO FaixaDePlaylist VALUES (3,27);
INSERT INTO FaixaDePlaylist VALUES (2,28);

#Mostre o nome dos usuários e username  que possuem plano  Casal 
SELECT u.NomeUsuario, u.Username
FROM Usuario u JOIN Plano p
ON (u.Plano = p.IdPlano )
WHERE p.Tipo = 'Casal'

#Mostre as músicas e a duração com duração maior que 350 de género Forro
SELECT m.NomeMusica, m.Duracao
FROM Genero g NATURAL JOIN Musica m
WHERE m.Duracao > 350
AND g.Genero = 'Forró'

#Liste as músicas e a data de lançamento do compositor Ary Barroso com Genero Pop
SELECT m.NomeMusica, m.DataLancamento
FROM Musica m NATURAL JOIN Compositor c NATURAL JOIN ComposicaoMusica cm NATURAL JOIN Genero g
WHERE c.NomeCompositor = 'Ary Barroso' 
AND g.Genero = 'Pop'


#Liste os albúm’s e a data de lancamento com produtor Eddie Krammer
SELECT  a.NomeAlbum, a.DataLancamento
FROM Album a NATURAL JOIN Produtor p NATURAL JOIN ProducaoMusica pm
WHERE p.NomeProdutor = 'Eddie Krammer'

#Busque os artistas com Seguidores maiores que 80 da Gravadora RCA Records
SELECT a.NomeArtista
FROM Artista a NATURAL JOIN Gravadora g
WHERE g.NomeGravadora = 'RCA Records'
AND a.Seguidores >= 80

#Listar  a gravadoras e seu respectivos nomes do artitas que começa com a letra A
SELECT g.NomeGravadora, a.NomeArtista
FROM Gravadora g LEFT JOIN Artista a
ON a.IdGravadora = g.IdGravadora
WHERE a.NomeArtista LIKE 'A%'

#Listar nome e usuario do plano free
SELECT u.Username, u.NomeUsuario
FROM Usuario u LEFT JOIN Plano p
ON u.Plano = p.IdPlano
WHERE p.Tipo = 'Free'

#Somar os minutos de gravação da artista Anita
SELECT SUM(m.duracao) AS 'Total Annita'
FROM Musica m NATURAL JOIN Artista a
WHERE a.NomeArtista = 'Anita'

#Mostrar quantos usuarios possuem plano Individual
SELECT COUNT(p.Tipo) AS 'Total Individual'
FROM Usuario u NATURAL JOIN Plano p
WHERE p.Tipo = 'Individual'
GROUP BY (p.Tipo)

#Liste o menor e maior número de seguidores do usuario
SELECT  MAX(u.Numseguidores) AS 'Maior', MIN(u.NumSeguidores) AS 'Menor'
FROM Usuario u

#Calcule a media de duração das músicas de cada produtor
SELECT p.NomeProdutor, AVG(m.Duracao) AS 'Media Produtor'
FROM Musica m NATURAL JOIN Produtor p NATURAL JOIN ProducaoMusica pm
GROUP BY (p.NomeProdutor)

#Mostrar a soma dos minutos de gravação de cada compositor
SELECT  c.NomeCompositor , SUM(m.Duracao) AS 'Duração do compositor'
FROM Musica m NATURAL JOIN Compositor c NATURAL JOIN ComposicaoMusica cm
GROUP BY (c.NomeCompositor)



