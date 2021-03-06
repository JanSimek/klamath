========
MAPS.TXT
========

MAPS.TXT contains parameters related to maps of areas in the game. There
are maps of cities, locations, and random encounters.

The file is a text format and is divided into tables describing
locations. Each table contains a list of variables which have values of
various types – text, numerical, combined. The order of variables in the
list does not appear to matter.

==1. Description of location tables== Each table starts with a header in
the format:

[Map 001]

This line marks the beginning of the table, and also gives it a unique
number (MAP ID). The highest possible number is 999, but this is
unlikely to become a practical concern. Looking up the table describing
a location can be done by name in the table describing locations (see
below), or by the table number. MAP ID, for example, is pointed to in
the same MAP file map location, in the properties of Exit Grids, in
scripts, and so on.

Immediately after the header is a list of variables.

==2. List of Variables== *''lookup\_name'' - name of the location
described in the table. This is the exact name indicated in WORLDMAP.TXT
in the section [Encounter Table N], and is used to look up the map
description in '''MAPS.TXT'''. Necessary parameter. *''map\_name'' -
name of the map file. Just the filename of the relevant MAP (in
"master.dat:raw-latex:`\maps`</code>"). Necessary parameter. *''music''
- name of the background music, excluding the ACM extension. See
''music\_path1'' in the '''[[CFG File Format
(settings)\|fallout2.cfg]]'''. This is, not surprisingly, the music that
will be played on this map. Necessary parameter, possibly (at least,
it's always used). *''ambient\_sfx'' - list of names of ambient sound
effect files to be played on this map (sound of the wind, gunfire in New
Reno, etc.). See files in
"master.dat:raw-latex:`\sound`:raw-latex:`\SFX`</code>" folder. Names
are followed by a colon, then a number indicating the frequency of the
effect (as a percentage), then a comma. This parameter is almost always
used, but is not necessary. (Note: percentages should sum to 100;
behavior if they don't is unknown.) *''pipboy\_active'' - has two
values: 'Yes' or 'No'. Used only on the Arroyo Temple maps (has the
value 'No' there). Given that you have the Pip-Boy everywhere else, this
parameter is not necessary. However, this is irrelevant as the engine
does not use this parameter; it just checks whether or not the 'Vault
Suit Recovery' movie has been played. *''saved'' - has two values: 'Yes'
(for cities) or 'No' (for random encounters). Apparently, this means
saving the state of the map - random encounters don't carry over to the
next one. Though some random encounters have the value 'Yes'. Special
encounters usually have the value 'Yes'. Necessary parameter. *''state''
- a very interesting parameter. When present, it has the value 'On'.
Perhaps it indicates if the player can immediately go to this map when
at the city (with the 'map' of the city), even without having been there
(i.e. 'opened' for him or her). *''dead\_bodies\_age'' - has two values:
'Yes' or 'No'. Means if saved bodies are preserved or not. For random
encounters it is 'No'. The default (i.e. if this parameter is not
present), is 'Yes'. *''can\_rest\_here'' - has two values: 'Yes' or
'No'. Mean if it's possible to rest on this map (comma-separated values
for all three levels of the map). For random encounters it is 'No'. The
default is 'Yes'. *''random\_start\_point\_N'' - the player's starting
coordinates on the map (for random encounters). Up to ten can be
specified (numbered 0 to 9). In general there are several points, and
are chosen at random when entering the map. Each consists of two text
parameters, separated by a colon. The first, elev, is the map level
(from 0 to 2); the second, tile\_num, is the hex number (for hex
coordinates see [[MAP File Format]]). Here the coordinates are written
in decimal notation; converted to hexadecimal form, the first byte will
be the horizontal coordinate and the second the vertical. (Example: say
we have "tile\_num:24103"; in hex that's 0x5E27, so the hex is at 0x5E
(94d) horizontally and 0x27 (39d) vertically.) In some random encounters
the starting point is not specified, especially at special encounters.
In these cases the starting point is apparently taken from the MAP file
(if there is one in it).

In most cases the variables for cities, random encounters, and special
encounters have some common theme, and take similar values. Therefore,
when it describes a location, the first looks like the other locations
of the same type.

[http://teamx.ru/site\_arc/docs/index.html Original location of
document] at teamx.ru (in Russian) [[Category:Fallout and Fallout 2 file
formats]][[Category:Translated TeamX documents]]
