command_set_cursor_text (Fep *fep,
                         FepControlMessage *request)
{
  FepAttribute attr;
  size_t str_len = strlen(request->args[0].str);
  if (str_len > FEP_MAX_CURSOR_TEXT_LENGTH) {
    // Handle error or truncate the string if necessary
    return;
  }
  if (_fep_control_message_read_attribute_arg (request, 1, &attr) == 0) {
    _fep_output_cursor_text (fep, request->args[0].str, &attr);
  }
}