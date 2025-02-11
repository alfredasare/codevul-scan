static json_t * oidc\_get\_state\_from\_cookie(request\_rec \*r, oidc\_cfg \*c,
const char \*cookieValue) {
json\_t \*result = NULL;
int ret;
json\_t \*json\_decoded = json\_loads(cookieValue, JSON\_DECODE\_ANY, &ret);
if (ret == 0 || json\_decoded == NULL) {
goaway(r, 400, "Invalid cookie value");
return NULL;
}
const char \*state\_str = json\_string\_value(json\_object\_get(json\_decoded, "state"));
if (!state\_str) {
goaway(r, 400, "Missing 'state' in cookie");
json\_decref(json\_decoded);
return NULL;
}
oidc\_util\_jwt\_verify(r, c->crypto\_passphrase, state\_str, &result);
json\_decref(json\_decoded);
return result;
}