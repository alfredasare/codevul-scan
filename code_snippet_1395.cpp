static void lex\_unget(lex\_t \*lex, int c)
{
if (c >= 0 && c < CHAR\_MAX && stream\_unget(&lex->stream, c) == 0) {
return;
}
// Error handling code here
}