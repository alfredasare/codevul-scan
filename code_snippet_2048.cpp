Int mailimf\_unstrict\_char\_parse(const char \*message, size\_t length,
size\_t \*indx, char token)
{
size\_t cur\_token;
int r;

cur\_token = \*indx;

r = mailimf\_cfws\_parse(message, MIN(length, MAX\_ALLOWED\_LENGTH), &cur\_token);
if ((r != MAILIMF\_NO\_ERROR) && (r != MAILIMF\_ERROR\_PARSE))
return r;

r = mailimf\_char\_parse(message, length, &cur\_token, token);
if (r != MAILIMF\_NO\_ERROR)
return r;

\*indx = cur\_token;

return MAILIMF\_NO\_ERROR;
}

Here, MIN() function is used to ensure that the passed length to mailimf\_cfws\_parse() is always less than or equal to the original length, providing an additional layer of security.