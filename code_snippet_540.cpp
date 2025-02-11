size_t incremental_sweep_phase(mrb_state *mrb, mrb_gc *gc, size_t limit)
{
  mrb_int n;
  mrb_sym *sym;
  size_t tried_sweep = 0;
  mrb_int h;
  mrb_sym **b = gc->sym_hashes[gc->sym_index];
  mrb_sym *buf = gc->sym_buf;
  size_t buf_size = sizeof(gc->sym_buf) / sizeof(mrb_sym);
  
  for (h = 0; h < MRB_HASH_SIZE; h++) {
    for (n = b[h]; n != 0; n = sym->next) {
      sym = mrb_hash_get(mrb, gc->sym_table, (char*)buf + tried_sweep);
      if (sym) {
        if (tried_sweep + sizeof(mrb_sym) > buf_size) {
          // Return early if we've reached the buffer limit
          return tried_sweep;
        }
        if (tried_sweep + sizeof(mrb_sym) <= limit) {
          // Copy the symbol if we have not exceeded the limit
          memcpy(buf + tried_sweep, &sym, sizeof(mrb_sym));
          tried_sweep += sizeof(mrb_sym);
        }
        else {
          // Otherwise, return the number of bytes tried
          return tried_sweep;
        }
      }
    }
  }
  return tried_sweep;
}