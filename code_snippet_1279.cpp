static char \*iscsi\_check\_valuelist\_for\_support(
struct iscsi\_param \*param,
char \*value)
{
char \*tmp1 = NULL, \*tmp2 = NULL;
char \*acceptor\_values = NULL, \*proposer\_values = NULL;
char \*tmp\_acceptor\_values = NULL, \*tmp\_proposer\_values = NULL;

if (!param || !value) {
return NULL;
}

acceptor\_values = param->value;
proposer\_values = value;

do {
if (!proposer\_values)
return NULL;
tmp\_proposer\_values = proposer\_values;
tmp1 = strchr(proposer\_values, ',');
if (tmp1) {
\*tmp1 = '\0';
}

acceptor\_values = param->value;
tmp\_acceptor\_values = acceptor\_values;

do {
if (!acceptor\_values) {
if (tmp1)
\*tmp1 = ',';
return NULL;
}
tmp2 = strchr(acceptor\_values, ',');
if (tmp2) {
\*tmp2 = '\0';
}
if (!strcmp(acceptor\_values, proposer\_values)) {
if (tmp2)
\*tmp2 = ',';
goto out;
}
if (tmp2)
\*tmp2++ = ',';

acceptor\_values = tmp2;
} while (acceptor\_values);
if (tmp1)
\*tmp1++ = ',';

proposer\_values = tmp1;
} while (proposer\_values);

out:
return tmp\_proposer\_values;
}