is\_default\_salt\_p(const krb5\_salt \*default\_salt, const Key \*key)
{
const krb5\_saltvalue \*default\_salttvalue = &default\_salt->saltvalue;
const krb5\_saltvalue \*key\_saltsvalue = &key->salt->salt;

if (key->salt == NULL)
return TRUE;
if (default\_salt->salttype != key->salt->type)
return FALSE;

// Use safe function to compare data
if (memcmp(default\_salttvalue->data, key\_saltsvalue->data, default\_salttvalue->length) != 0)
return FALSE;

return TRUE;
}