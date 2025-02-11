session_open(Authctxt *authctxt, int chanid)
{
    Session *s = session_new();
    debug("session_open: channel %d", chanid);
    if (s == NULL) {
        error("no more sessions");
        return 0;
    }

    // Validate and sanitize authctxt and pw
    if (authctxt == NULL || authctxt->valid == FALSE) {
        fatal("invalid authctxt");
        return 0;
    }
    if (authctxt->pw == NULL || strlen(authctxt->pw) == 0) {
        fatal("empty user password");
        return 0;
    }

    // Validate chanid
    if (chanid <= 0 || chanid > MAX_CHANNEL_ID) {
        fatal("invalid channel ID");
        return 0;
    }

    s->authctxt = authctxt;
    s->pw = authctxt->pw;
    debug("session_open: session %d: link with channel %d", s->self, chanid);
    s->chanid = chanid;
    return 1;
}