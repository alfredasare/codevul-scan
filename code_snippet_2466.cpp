#include <string.h>

#define MAX_TIMEZONE_LENGTH 128 // Adjust the maximum length as needed

DecodePosixTimezone(char *str, int *tzp)
{
	size_t strLength = strnlen(str, MAX_TIMEZONE_LENGTH);
	if (strLength >= MAX_TIMEZONE_LENGTH) {
		return -1;
	}

	char *cp = str;
	while (*cp != '\0' && isalpha((unsigned char) *cp))
		cp++;

	if (DecodeTimezone(cp, &tz) != 0 || *cp == '\0') {
		return -1;
	}

	char delim = *cp;
	*cp = '\0';
	int type = DecodeSpecial(MAXDATEFIELDS - 1, str, &val);
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
}	/* DecodePosixTimezone() */