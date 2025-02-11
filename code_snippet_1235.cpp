static void lex_unget(lex_t *lex, int c)
{
    if (c < 0 || c >= STREAM_BUFFER_SIZE) {
        return;
    }
    stream_unget(&lex->stream, c);
}