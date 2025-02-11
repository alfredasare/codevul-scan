int DecodePosixTimezone(char *str, int *tzp)
{
    int val, tz;
    int type;
    char buffer[MAX_TIMEZONE_LENGTH + 1];
    char *cp;
    char delim;

    if (strlen(str) > MAX_TIMEZONE_LENGTH) {
        return -1; // Error: input string too long
    }

    strcpy(buffer, str);

    cp = buffer;
    while (*cp != '\0' && isalpha((unsigned char) *cp))
        cp++;

    if (DecodeTimezone(cp, &tz) != 0)
        return -1;

    delim = *cp;
    *cp = '\0';

    type = DecodeSpecial(MAXDATEFIELDS - 1, buffer, &val);
    *cp = delim;

    switch (type)
    {
        case DTZ:
        case TZ:
            *tzp = (val * MINS_PER_HOUR) - tz;
            break;

        default:
            return -1;
    }

    return 0;
}