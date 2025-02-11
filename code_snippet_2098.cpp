static void charstring\_start(void)
{
int i;

if (!charstring\_buf) {
charstring\_bufsiz = 65536;
if (!(charstring\_buf = (byte *) malloc(charstring\_bufsiz)))
fatal\_error("out of memory");
}

charstring\_bp = charstring\_buf;
cr = 4330;
for (i = 0; i < lenIV && charstring\_bp < charstring\_buf + charstring\_bufsiz; i++)
\*charstring\_bp++ = cencrypt((byte) 0);
}