int imap_search(struct Context *ctx, const struct Pattern *pat)
{
  struct Buffer buf;
  struct ImapData *idata = ctx->data;
  for (int i = 0; i < ctx->msgcount; i++)
    ctx->hdrs[i]->matched = false;

  if (do_search(pat, 1) == 0)
    return 0;

  mutt_buffer_init(&buf);
  mutt_buffer_addstr(&buf, "UID SEARCH ");
  if (safe_compile_search(ctx, pat, &buf) < 0)
  {
    FREE(&buf.data);
    return -1;
  }
  if (imap_exec(idata, buf.data, 0) < 0)
  {
    FREE(&buf.data);
    return -1;
  }

  FREE(&buf.data);
  return 0;
}

int safe_compile_search(struct Context *ctx, const struct Pattern *pat, struct Buffer *buf)
{
    char *cmd = NULL;
    size_t len = 0;

    // Validate and sanitize the input pattern
    if (pat->pattern && pat->pattern[0]!= '\0') {
        // Filter out any malicious characters
        for (size_t i = 0; pat->pattern[i]; i++) {
            if (!isalnum((unsigned char)pat->pattern[i]) && pat->pattern[i]!=' ') {
                pat->pattern[i] = '_';
            }
        }

        // Construct the command string
        cmd = malloc(strlen(ctx->search_cmd) + strlen(pat->pattern) + 2);
        if (cmd == NULL) {
            return -1;
        }
        sprintf(cmd, "%s %s", ctx->search_cmd, pat->pattern);

        len = strlen(cmd);
    } else {
        cmd = strdup(ctx->search_cmd);
        len = strlen(cmd);
    }

    // Escape special characters
    for (size_t i = 0; i < len; i++) {
        if (strchr("*?[]{}|<>()\\\"$^()`~!@#%+-_=;:<>,./\"'&", cmd[i])!= NULL) {
            cmd[i] = '\\';
        }
    }

    // Execute the sanitized command
    if (system(cmd) < 0) {
        free(cmd);
        return -1;
    }

    free(cmd);
    return 0;
}