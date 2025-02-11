DEFINE\_RUN\_ONCE\_STATIC(ossl\_init\_engine\_afalg)
{
#   ifdef OPENSSL\_INIT\_DEBUG
 fprintf(stderr, "OPENSSL\_INIT: ossl\_init\_engine\_afalg: "
 "\_engine\_load\_afalg\_int()\n");
#   endif
 if (engine\_is\_available("afalg")) {
 engine\_load\_afalg\_int();
 }
 return 1;
}