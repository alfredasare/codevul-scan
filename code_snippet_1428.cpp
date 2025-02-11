CC_ESC_WARN(ScanEnv* env, UChar *c)
{
  if (onig_warn == onig_null_warn) return ;

  if (IS_SYNTAX_BV(env->syntax, ONIG_SYN_WARN_CC_OP_NOT_ESCAPED) &&
      IS_SYNTAX_BV(env->syntax, ONIG_SYN_BACKSLASH_ESCAPE_IN_CC)) {
    UChar buf[WARN_BUFSIZE];
    size_t buf_len = WARN_BUFSIZE - 1; // leave room for null-termination
    int num_written = onig_snprintf(buf, buf_len, env->enc,
                                    env->pattern, env->pattern_end,
                                    (UChar*) "%s character class has '%s' without escape",
                                    c);
    if (num_written >= buf_len) {
      // buffer overflow detected, handle error
      return;
    }
    buf[buf_len] = '\0'; // null-terminate the buffer
    (*onig_warn)((char*) buf);
  }
}