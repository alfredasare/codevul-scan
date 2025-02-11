g\_NP\_GetMIMEDescription(void)
{
if (g\_plugin\_NP\_GetMIMEDescription == NULL)
return NULL;

D(bugiI("NP\_GetMIMEDescription\n"));
char \*str = g\_plugin\_NP\_GetMIMEDescription();
if (str == NULL) {
D(bugiE("NP\_GetMIMEDescription returned NULL\n"));
return NULL;
}
return str;
}