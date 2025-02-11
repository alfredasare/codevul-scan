void postresqlNoticeHandler(void *arg, const char *message)
{
  layerObj *lp;
  lp = (layerObj*)arg;

  const char *sanitizedMessage = mysql_real_escape_string(lp->db, message, 0, strlen(message));

  if (lp->debug) {
    msDebug("%s\n", sanitizedMessage);
  }
}