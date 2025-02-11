static const GQuark quark = g_quark_from_static_string("my_object_error");

GQuark
my_object_error_quark (void)
{
  return quark;
}