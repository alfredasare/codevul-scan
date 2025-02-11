void mrb_fiber_resume(mrb_state *mrb, mrb_value fib, mrb_int len, const mrb_value *a)
{
  size_t buffer_size = mrb_get_string_buffer_size(mrb, fib);
  if (len > buffer_size) {
    mrb_raise(mrb, E_RangeError, "Out-of-bounds write");
    return;
  }
  return fiber_switch(mrb, fib, len, a, TRUE, TRUE);
}