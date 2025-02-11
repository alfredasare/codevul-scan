mrb_io_s_for_fd(mrb_state *mrb, mrb_value klass)
{
  struct RClass *c = mrb_class_ptr(klass);
  mrb_value obj;

  obj = mrb_obj_new(mrb, c, 0, NULL);
  return mrb_io_initialize(mrb, obj);
}