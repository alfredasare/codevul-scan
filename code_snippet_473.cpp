cpl_flush()
{
  struct cpelement *cpe, *next_cpe;

  for (cpe = coproc_list.head; cpe; )
  {
    next_cpe = cpe->next;

    coproc_dispose(cpe->coproc);
    cpe_dispose(cpe);

    cpe = next_cpe;
  }

  coproc_list.head = coproc_list.tail = 0;
  coproc_list.ncoproc = 0;
}