# simple-piano-sheets
Markup language to represent simple piano music sheets, the characteristics it's able to represent are:
Playing hand, Clef, keysign, time signature, notes (which octave the note is in, it’s length, tone, pitch, length and whether it has an accidental or not), chords, slurs, ties, and rests. <br />
This repository contains the productions used for the language, and a C++ program that validates whether a string is valid or not.

## Rule productions used:
START -> {CLEF,KEYSIGN,TIMESIG, NEW}{CLEF,KEYSIGN,TIMESIG, NEW} <br />
CLEF -> G|F <br />
KEYSIGN -> +CIRCLE | -CIRCLE | 0 <br />
CIRCLE-> [1-11] <br />
TIMESIG -> NUM/NUM <br />
NUM -> [1-64] <br />
NEW -> ELEM, NEW | ELEM | ε <br /> 
ELEM -> NOTE | REST | CHORD | SLUR | TIE <br />
CHORD -> c(GROUP) <br /> 
SLUR -> s(GROUP) <br />
TIE -> t(NUM)NOTE <br />
GROUP -> GROUP. NOTE | NOTE <br />
NOTE-> --TONE |-TONE  | TONE | +TONE | ++TONE  <br />
TONE-> PITCH| PITCH LENGTH <br />
PITCH -> C|D|E|F|G|A|B <br />
LENGTH -> +BASE | -BASE <br />
BASE -> 2 | 4 <br />
REST-> R | R LENGTH <br />

