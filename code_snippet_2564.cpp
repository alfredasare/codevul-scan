static void tcp\_illinois\_init(struct sock \*sk)
{
 struct illinois \*ca = inet\_csk\_ca(sk);

 ca->alpha = ALPHA\_MAX;
 ca->beta = BETA\_BASE;
 ca->base\_rtt = 0x7fffffff;
 ca->max\_rtt = 0;

 ca->acked = 0;
 ca->rtt\_low = 0;
 ca->rtt\_above = 0;

 rtt\_reset(sk);
}

char \*sanitize\_input(char \*input)
{
 char \*sanitized = malloc(strlen(input)+1);
 char \*s = sanitized;
 char \*end = sanitized + strlen(input);

while (input < end) {
if (\*input != '.' || (input+1 < end && *(input+1) != '.')) {
\*s++ = \*input;
}
input++;
}

\*s = '\0';

return sanitized;
}

Note: The sanitize\_input function only allows single '.' characters in the input string, and removes any '..' or '/' characters. This function should be adapted to fit the specific needs of the application.