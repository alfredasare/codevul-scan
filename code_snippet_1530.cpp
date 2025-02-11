int __key\_link\_check\_live\_key(struct key \*keyring, struct key \*key)
{
 struct key \*key\_snapshot;
 int ret;

 key\_snapshot = get\_key\_ref(key);
 if (!key\_snapshot)
 return -ENOMEM;

 if (key\_snapshot->type == &key\_type\_keyring)
 ret = keyring\_detect\_cycle(keyring, key\_snapshot);
 else
 ret =