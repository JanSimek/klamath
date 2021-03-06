===
GAM
===

GAM files are '''''indexed text''''' files. They contain global
variables for each core ''Fallout game'' and its maps, and are found in
master.dat:raw-latex:`\data` and master.dat:raw-latex:`\maps`,
respectively.

Format and editing of GAM files is identical between ''Fallout 1'' and
''2''.

==Structure== At the beginning there is a header - "MAP\_GLOBAL\_VARS:"
in GAM files for maps and "GAME\_GLOBAL\_VARS:" in VAULT13.GAM.

Next is a list of variables - first the name (as in most programming
languages it can contain Latin letters, numbers, and underscores, as in
"MVAR\_Last\_Respawn\_Map"), then the assignment operator (:=,
attributed to Pascal, Fallout's proprietary scripting lanugage), then
the initial value of the variable, and at the end a semicolon.

Variables are referred to in scripts by their number in the list
(starting at zero).

Variable names are always written with capitalized internal words to
distinguish them from map variables, and following each variable is a
comment with its number. This is done for the convenience of
programmers.

===Notes=== \* Comments are indicated by two slashes (//), attributed to
C, one of Fallout's programming languages. \* '''Do not exceed 256
characters in any one line''' in this file. Any lines above 256
characters will overflow into the following line, causing all global
variables after that to hold incorrect data.

===Example 1=== Taken from ARGARDEN.GAM, which corresponds to the
ARGARDEN.MAP file (''Fallout 2''):

.. raw:: html

   <pre>
    // Map vars for Arroyo Garden Map

    // Comments

   //MAP_GLOBAL_VARS:
   MAP_GLOBAL_VARS:
   //GLOBAL                                        NUMBER

   MVAR_Last_Respawn_Map           :=0;            //      (0)
   MVAR_Current_Gecko_Easy         :=0;            //      (1)
   MVAR_Current_Gecko_Hard         :=0;            //      (2)
   MVAR_Current_Xander_Root        :=0;            //      (3)
   MVAR_Current_Broc_Flower        :=0;            //      (4)
   MVAR_Last_Spot                  :=0;            //      (5)
   MVAR_Kill_Runaway               :=0;            //      (6)
   MVAR_Dog_Already_Dead           :=0;            //      (7)
   </pre>

===Example 2=== Taken from VAULT13.GAM (''Fallout 2''):

.. raw:: html

   <pre>
   GAME_GLOBAL_VARS:
   //GLOBAL                                                NUMBER

   GVAR_PLAYER_REPUTATION                  :=0;    //      (0)
   GVAR_CHILDKILLER_REPUTATION             :=0;    //      (1)
   GVAR_CHAMPION_REPUTATION                :=0;    //      (2)
   GVAR_BERSERKER_REPUTATION               :=0;    //      (3)
   GVAR_BAD_MONSTER                        :=0;    //      (4)
   GVAR_GOOD_MONSTER                       :=0;    //      (5)
   GVAR_PLAYER_MARRIED                     :=0;    //      (6)
   GVAR_ENEMY_ARROYO                       :=0;    //      (7)
   </pre>

===Open with=== .GAM files can be opened with any simple text-editing
programs, like Notepad or WordPad.

==TeamX document== [http://www.teamx.ru/rus/bd/gam\_format.shtml
Original document] at teamx.ru (in Russian) [[Category:Fallout and
Fallout 2 file formats]][[Category:Translated TeamX documents]]
