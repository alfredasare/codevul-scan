mrb_mod_instance_methods(mrb_state *mrb, mrb_value mod)
{
  struct RClass *c = mrb_class_ptr(mod);
  mrb_bool recur = FALSE; // default value
  mrb_get_args(mrb, "|b", &recur);
  if (!recur) {
    recur = FALSE; // set to false if not explicitly set
  }
  return mrb_class_instance_method_list(mrb, recur, c, 0);
}