iakerb_make_finished(krb5_context context, krb5_key key, const krb5_data *conv, krb5_data **finished)
{
krb5_error\_code code;
krb5\_iakerb\_finished iaf;

\*finished = NULL;

memset(&iaf, 0, sizeof(iaf));

if (key == NULL || key->length == 0)
return KRB5KDC\_ERR\_NULL\_KEY;

code = krb5\_k\_make\_checksum(context, 0, key, KRB5\_KEYUSAGE\_IAKERB\_FINISHED,
conv, &iaf.checksum);
if (code != 0)
return code;

code = encode\_krb5\_iakerb\_finished(&iaf, finished);

krb5\_free\_checksum\_contents(context, &iaf.checksum);

return code;
}