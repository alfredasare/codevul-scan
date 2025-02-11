command_set_cursor_text (Fep *fep, FepControlMessage *request)
{
  FepAttribute attr;
  int index;

  if (_fep_control_message_read_attribute_arg (request,