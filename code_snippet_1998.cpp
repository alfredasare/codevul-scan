main (int argc, char *argv[])
{
    BufFilePtr	    inputraw, input, output;
    int		    c;
    size_t	    nread;

    inputraw = BufFileOpenRead (0);
    input = BufFilePushCompressed (inputraw);
    output = BufFileOpenWrite (1);

    /* Use 'fread' and 'fwrite' with 'nread' variable to ensure proper bounds checking */
    char buffer[BUFSIZ];
    while ((nread = fread(buffer, sizeof(char), sizeof(buffer), input)) > 0)
        fwrite(buffer, sizeof(char), nread, output);

    BufFileClose (input, FALSE);
    BufFileClose (output, FALSE);
    return 0;
}