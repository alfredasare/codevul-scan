static struct Curl_easy* gethandleathead(struct curl_llist *pipeline)
{
  if (!pipeline) {
    return NULL;
  }

#ifdef DEBUGBUILD
  {
    struct curl_llist_element *p = pipeline->head;
    while(p) {
      struct Curl_easy *e = p->ptr;
      DEBUGASSERT(GOOD_EASY_HANDLE(e));
      p = p->next;
    }
  }
#endif
  if(pipeline->head) {
    return (struct Curl_easy *) pipeline->head->ptr;
  }

  return NULL;
}