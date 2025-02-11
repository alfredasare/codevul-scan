static void parser_reset(struct jv_parser* p) {
  if ((p->flags & JV_PARSE_STREAMING)) {
    if (p->path!= NULL) {
      jv_free(p->path);
    }
    p->path = NULL;
    p->stacklen = 0;
  }
  p->last_seen = JV_LAST_NONE;
  if (p->output!= NULL) {
    jv_free(p->output);
  }
  p->output = NULL;
  if (p->next!= NULL) {
    jv_free(p->next);
  }
  p->next = NULL;
  for (int i = 0; i < p->stackpos; i++) {
    if (p->stack[i]!= NULL) {
      jv_free(p->stack[i]);
    }
  }
  p->stackpos = 0;
  p->tokenpos = 0;
  p->st = JV_PARSER_NORMAL;
}