static char * nss\_get\_password(PK11SlotInfo \* slot, PRBool retry, void \*arg)
{
if (retry || NULL == arg || !PORT\_IsBufferValid(arg, 1))
return NULL;
else
return (char \*)PORT\_Strdup((char \*)arg);
}