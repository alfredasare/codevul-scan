mrb_mod_instance_methods(mrb_state *mrb, mrb_value mod)
{
  struct RClass *c = mrb_class_ptr(mod);
  if (!c) {
    mrb_raise(mrb, E_TYPE_ERROR, "expected a class");
    return mrb_nil_value();
  }
  mrb_bool recur = TRUE;
  mrb_get_args(mrb, "|b", &recur);
  return mrb_class_instance_method_list(mrb, recur, c, 0);
}