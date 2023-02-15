# simple-piano-sheets
Markup language to represent simple piano music sheets, the characteristics it's able to represent are:
Playing hand, Clef, keysign, time signature, notes (which octave the note is in, it’s length, tone, pitch, length and whether it has an accidental or not), chords, slurs, ties, and rests.

## Rule productions used:
START -> {CLEF,KEYSIGN,TIMESIG, NEW}{CLEF,KEYSIGN,TIMESIG, NEW}
CLEF -> G|F
KEYSIGN -> +CIRCLE | -CIRCLE | 0
CIRCLE-> [1-11]
TIMESIG -> NUM/NUM
NUM -> [1-64]
NEW -> ELEM, NEW | ELEM | ε
ELEM -> NOTE | REST | CHORD | SLUR | TIE
CHORD -> c(GROUP)
SLUR -> s(GROUP)
TIE -> t(NUM)NOTE
GROUP -> GROUP. NOTE | NOTE
NOTE-> --TONE |-TONE  | TONE | +TONE | ++TONE 
TONE-> PITCH| PITCH LENGTH 
PITCH -> C|D|E|F|G|A|B
LENGTH -> +BASE | -BASE
BASE -> 2 | 4
REST-> R | R LENGTH

