===
LIP
===

A Description of the LIP File Format v2 Used in Fallout 2

This document will describe the internals of the .LIP format (version 2)
used in the Fallout 2 engine. This information was obtained through the
analysis of the corresponding functions found in Fallout2.exe

===1. FRM files: The Talking Heads===

The name of the files used for graphical conversation takes the
following form.

RootSuffix1Suffix2[Sufix3].frm

Where:

Root - Root file name eg. “ELDER” (5 characters)

Suffix1 - 1st suffix, indicates disposition (1 character)

Suffix2 - 2nd suffix, indicates file contents (1 character)

Suffix3 - 3rd suffix, indicates index number for fidget files (usually 1
character but theoretically could be more if you had over 9 fidget
files)

The first suffix indicates that the graphics in this .FRM file have a
certain disposition. G is good, B is bad, N is neutral. The second
suffix indicates what type of animation is contained in the file,
transition, fidgeting or phonemes. Transition animations show a person
moving from one disposition to another. Fidgeting animations show the
character blinking or nodding or something. Phoneme animations contain 9
possible positions for the characters mouth to be in. These are the ones
that are used within the .LIP file format.

The possible values and their meanings for the suffixes are given in
table 1.1

Table 1.1 – Values of suffix1, suffix2, suffix3 and their purpose.

{\| class="wikitable" border="1" ! Suffix1 !! Suffix2 !! Suffix3 !!
Purpose \|- \| ‘g’ \|\| ‘v’ \|\| - \|\| Unknown, no files use this
combination \|- \| ‘g’ \|\| ‘f’ \|\| 1,2,… \|\| Fidget animations for
the “good” disposition \|- \| ‘g’ \|\| ‘n’ \|\| - \|\| Transition
animation from good to neutral disposition \|- \| ‘n’ \|\| ‘g’ \|\| -
\|\| Transition animation from neutral to good disposition \|- \| ‘n’
\|\| ‘f’ \|\| 1,2,… \|\| Fidget animations for the “neutral” disposition
\|- \| ‘n’ \|\| ‘b’ \|\| - \|\| Transition animation from neutral to bad
disposition \|- \| ‘b’ \|\| ‘n’ \|\| - \|\| Transition animation from
bad to neutral disposition \|- \| ‘b’ \|\| ‘f’ \|\| 1,2,… \|\| Fidget
animations for the “bad” disposition \|- \| ‘b’ \|\| ‘v’ \|\| - \|\|
Unknown, no files use this combination \|- \|\| ‘g’ \|\| ‘p’ \|\| - \|\|
Phoneme images for the “good” disposition \|- \| ‘n’ \|\| ‘p’ \|\| -
\|\| Phoneme images for the “neutral” disposition \|- \| ‘b’ \|\| ‘p’
\|\| - \|\| Phoneme images for the “bad” disposition \|} NOTE: The
maximum values for the fidget file numbers (suffix3) are determined in
the “heads.lst” file (in /data/art/heads). This file is formatted as
such: ROOT X, Y, Z Where ROOT is the root filename, X is the number of
“good” fidget files, Y is the number of “neutral” fidget files and Z is
the number of “bad” fidget files.

Example Root file name: myron. [[Image:LIP\_en\_html\_2efb00c9.jpg]]

NOTE: Phoneme files (with suffix3 == ‘p’) must have at least 9 frames.
There can be more, but the engine will only use the first 9.

NOTE: The game engine will play a random fidget file at the end of each
speech segment which corresponds to the current disposition.

==2. LIP File Format ver. 2==

| {\| class="wikitable" border="1" !Offset !! Size (bytes) !! Data type
  !! Description \|- \| 0x0000 \|\| 4 \|\| unsigned \|\| File type
  version. Fallout 2 uses version 2. \|- \| 0x0004 \|\| 4 \|\| unsigned
  = 0x00005800 \|\| Unknown. It is always set to 0x00005800 however and
  is read by fallout2.exe but is never used. \|- \| 0x0008 \|\| 4 \|\|
  unsigned \|\| Unknown. During testing these values made no changes to
  playback. Usually 0x00000000. \|- \| 0x000С \|\| 4 \|\| unsigned \|\|
  Unknown. This value is read by fallout2.exe but is never used. Usually
  0x00000000. \|- \| 0x0010 \|\| 4 \|\| unsigned \|\| The length of the
  unpacked ACM file. (See NOTE 2) This value is read by fallout2.exe and
  divided by the number of phoneme markers but is not used. \|- \|
  0x0014 \|\| 4 \|\| unsigned \|\| NUM-OF-PHONEMS: Total number of
  phoneme codes used in this file. \|- \| 0x0018 \|\| 4 \|\| unsigned
  \|\| Unknown. This value is read by fallout2.exe but is never
  used.Usually 0x00000000. \|- \| 0x001С \|\| 4 \|\| unsigned \|\|
  NUM-OF-MARKERS: Total number of position markers stored in this file.
  Always equal to(NUM-OF-PHONEMES + 1) because a 0 secondframe with the
  mouth closed is inserted to the beginning of each speech sequence. \|-
  \| 0x0020 \|\| 8 \|\| char[8] \|\| Name of the corresponding ACM file
  for this .LIP file. Must not be greater than 7 bytes and must be null
  terminated. (ie. 0x00) \|- \|\| 0x0028 \|\| 4 \|\| char[4] = “VOC”
  \|\| Read by fallout2.exe and then converted from .VOC to .ACM then
  not used. Probably during development they switched from .voc file
  format to ACM and just hacked in this change to adapt. This is also
  null terminated. (0x00) \|- \| 0x002С \|\| 1 \|\| unsigned =
  [0x00..0x29] \|\| PHONEM-0: Phoneme 0 This is the first byte in a
  single byte list of phoneme codes which correspond to a frame in the
  .FRM file being used. (See table 2.1) \|- \| 0x002D \|\| 1 \|\|
  unsigned = [0x00 .. 0x29] \|\| PHONEM-1: Phoneme 1
| \|- \| … \|\| \|\| \|\|
| \|- \| 0x002C + NUM-OF-PHONEMS \|\| 4 \|\| unsigned = [0,1] \|\|
  MARKER-TYPE-0: Type marker 0 This type code is read by fallout2.exe
  but is not used. \|- \| 0x0030 +NUM-OF-PHONEMS \|\| 4 \|\| unsigned
  \|\| MARKER-SAMPLE-0: Offset in unpacked ACM when phoneme must be
  shown \|- \| 0x0034 + NUM-OF-PHONEMS \|\| 4 \|\| unsigned = [0,1] \|\|
  MARKER-TYPE-1: Type marker 1 \|- \| 0x0038 +NUM-OF-PHONEMS \|\| 4 \|\|
  unsigned \|\| MARKER-SAMPLE-1: Offset in unpacked ACM when phoneme
  must be shown \|- \| … \|\| \|\| \|\|
| \|}

NOTE 1: MARKER-TYPE-0 must have value 0x00000001, and MARKER-SAMPLE-0
must have 0x00000000.

==Table 2.1 – Relationship between value of Phoneme listed in the .LIP
file and the frame in the corresponding .FRM file.==

| {\| class="wikitable" border="1" ! Phoneme !! Frame !! Phoneme !!
  Frame !! Phoneme !! Frame \|- \| 0x00 \|\| 0\|\| 0x10 \|\| 7 \|\| 0x20
  \|\| 6 \|- \| 0x01 \|\| 3 \|\| 0x11 \|\| 6 \|\| 0x21 \|\| 2 \|- \|
  0x02 \|\| 1 \|\| 0x12 \|\| 6 \|\| 0x22 \|\| 2 \|- \| 0x03 \|\| 1 \|\|
  0x13 \|\| 2 \|\| 0x23 \|\| 5 \|- \| 0x04 \|\| 3 \|\| 0x14 \|\| 2 \|\|
  0x24 \|\| 8 \|- \| 0x05 \|\| 1 \|\| 0x15 \|\| 2 \|\| 0x25 \|\| 2 \|-
  \| 0x06 \|\| 1 \|\| 0x16 \|\| 2 \|\| 0x26 \|\| 2 \|- \| 0x07 \|\| 1
  \|\| 0x17 \|\| 4 \|\| 0x27 \|\| 2 \|- \| 0x08 \|\| 7 \|\| 0x18 \|\| 4
  \|\| 0x28 \|\| 2 \|- \| 0x09 \|\| 8 \|\| 0x19 \|\| 5 \|\| 0x29 \|\| 8
  \|- \| 0x0A \|\| 7 \|\| 0x1A \|\| 5 \|\| \|\|
| \|- \| 0x0B \|\| 3 \|\| 0x1B \|\| 2 \|\| \|\|
| \|- \| 0x0C \|\| 1 \|\| 0x1C \|\| 2 \|\| \|\|
| \|- \| 0x0D \|\| 8 \|\| 0x1D \|\| 2 \|\| \|\|
| \|- \| 0x0E \|\| 1 \|\| 0x1E \|\| 2 \|\| \|\|
| \|- \| 0x0F \|\| 7 \|\| 0x1F \|\| 2 \|\| \|\|
| \|}

==3. About the Author==

Author: Anchorite

E-mail: anchorite2001@yandex.ru

The author wishes to thank Abel for his input about the ACM file format.

English Translation: phro

Email: phro at rogers.com

Some additional by Anchorite.

Found in [[TeamX]]'s [http://www.teamx.ru/eng/files/docs/index.shtml
offline docs][[Category:Fallout and Fallout 2 file formats]]
