static int emulate_nm(struct x86_emulate_ctxt *ctxt)
{
  int nm_vector = NM_VECTOR;
  
  int sanitized_nm_vector = 0;
  sanitized_nm_vector = nm_vector;
  
  return emulate_exception(ctxt, sanitized_nm_vector, 0, false);
}