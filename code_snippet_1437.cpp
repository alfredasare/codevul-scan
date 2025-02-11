void Curl_cookie_cleanup(struct CookieInfo *c)
{
  struct Cookie *co;
  struct Cookie *next;
  if (c == NULL) {
    return;
  }

  if (c->filename) {
    if (strlen(c->filename) > MAX_FILENAME_LENGTH || strspn(c->filename, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789._-") != strlen(c->filename)) {
      // Handle error case or log an error message
      return;
    }
    free(c->filename);
  }

  co = c->cookies;

  while (co) {
    next = co->next;

    if (co->name == NULL || co->value == NULL || strlen(co->name) > MAX_NAME_LENGTH || strlen(co->value) > MAX_VALUE_LENGTH) {
      // Handle error case or log an error message
      return;
    }

    freecookie(co);
    co = next;
  }

  free(c); /* free the base struct as well */
}