gc_gray_counts(mrb_state *mrb, mrb_gc *gc, struct RBasic *obj)
{
  size_t children = 0;

  switch (obj->tt) {
  case MRB_TT_ICLASS:
    children++;
    break;

  case MRB_TT_CLASS:
  case MRB_TT_SCLASS:
  case MRB_TT_MODULE:
    {
      struct RClass *c = (struct RClass*)obj;

      children += mrb_gc_mark_iv_size(mrb, (struct RObject*)obj);
      children += mrb_gc_mark_mt_size(mrb, c);
      children++;
    }
    break;

  case MRB_TT_OBJECT:
  case MRB_TT_DATA:
  case MRB_TT_EXCEPTION:
    children += mrb_gc_mark_iv_size(mrb, (struct RObject*)obj);
    break;

  case MRB_TT_ENV:
    children += MRB_ENV_LEN(obj);
    break;

  case MRB_TT_FIBER:
    {
      struct mrb_context *c = ((struct RFiber*)obj)->cxt;
      size_t i;
      mrb_callinfo *ci;

      if (!c || c->status == MRB_FIBER_TERMINATED) break;

      /* mark stack */
      i = c->stack - c->stbase;

      if (c->ci) {
        i += ci_nregs(c->ci);
      }
      if (c->stbase + i > c->stend) i = c->stend - c->stbase;
      children += i;

      /* mark ensure stack */
      children += c->eidx;

      /* mark closure */
      if (c->cibase) {
        for (i=0, ci = c->cibase; ci <= c->ci; i++, ci++)
          ;
      }
      children += i;
    }
    break;

  case MRB_TT_ARRAY:
    {
      struct RArray *a = (struct RArray*)obj;
      children += ARY_LEN(a);
    }
    break;

  case MRB_TT_HASH:
    children += mrb_gc_mark_iv_size(mrb, (struct RObject*)obj);
    children += mrb_gc_mark_hash_size(mrb, (struct RHash*)obj);
    break;

  case MRB_TT_PROC:
  case MRB_TT_RANGE:
    children+=2;
    break;

  default:
    break;
  }
  return children;
}