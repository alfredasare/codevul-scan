my_object_error_quark (void)
{
  static GQuark quark = 0;
  if (!quark)
  {
    const gchar *error_string = "my_object_error";
    quark = g_quark_from_static_string (error_string);
  }
  return quark;
}