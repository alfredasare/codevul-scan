void Curl_cookie_cleanup(struct CookieInfo *c)
{
  struct Cookie *co;
  struct Cookie *next;
  if(c) {
    if(c->filename)
      free(c->filename);
    co = c->cookies;

    while(co) {
      next = co->next;
      if(freecookie(co)!= 0) {
        perror("Error freeing cookie");
        exit(1);
      }
      co = next;
    }
    free(c); /* free the base struct as well */
  }
}