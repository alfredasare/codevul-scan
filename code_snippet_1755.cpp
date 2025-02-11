VOID ixheaacd\_shiftrountine(WORD32 \*qmf\_real, WORD32 \*qmf\_imag, WORD32 len, WORD32 common\_shift) {
WORD32 treal, timag;
WORD32 j;

if (common\_shift < 0) {
WORD32 cshift = -common\_shift;
cshift = ixheaacd\_min32(cshift, 31);
for (j = len - 1; j >= 0; j--) {
treal = \*qmf\_real;
timag = \*qmf\_imag;

if ((WORD64)treal << cshift != (treal << cshift)) { // Check for overflow
break;
}
treal = ixheaacd\_shl32(treal, cshift);

if ((WORD64)timag << cshift != (timag << cshift)) { // Check for overflow
break;
}
timag = ixheaacd\_shl32(timag, cshift);

\*qmf\_real++ = treal;
\*qmf\_imag++ = timag;
}
} else {
for (j = len - 1; j >= 0; j--) {
if ((WORD64)\*qmf\_real > (MAX\_WORD32 - ((\~0U) << common\_shift))) { // Check for overflow
break;
}
\*qmf\_real = ixheaacd\_shl32(\*qmf\_real, common\_shift);

if ((WORD64)\*qmf\_imag > (MAX\_WORD32 - ((\~0U) << common\_shift))) { // Check for overflow
break;
}
\*qmf\_imag = ixheaacd\_shl32(\*qmf\_imag, common\_shift);

\*qmf\_real++ = treal;
\*qmf\_imag++ = timag;
}
}
}

Note: The macro MAX\_WORD32 is defined as (WORD32)-1, and (\~0U) is used to represent a 32-bit unsigned integer with all bits set to 1. These are added to check for possible integer overflows during left shifts.