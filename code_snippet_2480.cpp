static int _converse(pam_handle_t *pamh, int nargs,
                     const struct pam_message **message,
                     struct pam_response **response) {
  struct pam_conv *conv;
  int retval;

  retval = pam_get_item(pamh, PAM_CONV, (void *)&conv);

  if (retval != PAM_SUCCESS) {
    return retval;
  }

  const char* format = "The message is: %s";

  *response = calloc(nargs, sizeof(struct pam_response));

  for (int i = 0; i < nargs; i++) {
    (*response)[i].resp_retcode = 0;
    (*response)[i].resp = strdup(message[i]->msg);
  }

  return conv->conv(nargs, (const struct pam_message **)message, *response, conv->appdata_ptr);
}