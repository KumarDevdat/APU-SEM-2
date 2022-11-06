


-- 1.
SELECT count(distinct LOC_TYPE) AS "Total Unique Location" FROM VENUES;
 
-- 2.

SELECT count(EMAIL) AS "Clients with Email" FROM CLIENTS WHERE EMAIL IS NOT NULL;
 
-- 3.
SELECT SONG_ID FROM PLAY_LIST_ITEMS WHERE EVENT_ID = ALL (SELECT EVENT_ID FROM PLAY_LIST_ITEMS WHERE SONG_ID = 45);
 
-- 4.
SELECT TRACK, CD_NUMBER FROM TRACK_LISTINGS WHERE CD_NUMBER = ALL (SELECT CD_NUMBER FROM CDS WHERE TITLE = 'Party Music for All Occasions')
 
-- 5.
SELECT SONG_ID, TITLE, DURATION, ARTIST FROM SONGS WHERE TYPE_CODE = ANY(SELECT CODE FROM SONG_TYPES WHERE TYPE_DESCRIPTION = 'Jazz' or TYPE_DESCRIPTION = 'Pop');
 
-- 6.
SELECT EVENT_NAME, PACKAGE_CODE AS 'code' FROM DJ_EVENTS INNER JOIN PACKAGES ON DJ_EVENTS.PACKAGE_CODE = PACKAGES.CODE;
 
-- 7.
SELECT TITLE, ARTIST, TYPE_CODE, TYPE_DESCRIPTION FROM SONGS FULL OUTER JOIN SONG_TYPES ON SONGS.TYPE_CODE = SONG_TYPES.CODE;
 
-- 8.
CREATE TABLE MENUS
(
    Menu_Code varchar(3) NOT NULL PRIMARY KEY,
    Menu_Type varchar(30) NOT NULL
)
 
-- 9.
CREATE TABLE FOOD_ITEMS
(
    Food_Item_Code varchar(5) NOT NULL PRIMARY KEY,
    Food_Description varchar(100) NOT NULL,
    Price decimal(8, 2) NOT NULL,
    Menu_No varchar(3) FOREIGN KEY REFERENCES Menus
)
 
-- 10.
ALTER table Menus
ADD Hours_Served varchar(30) NOT NULL;

