cpl_flush ()
{
  struct cpelement *cpe, *p;
  int i;

  if (!coproc_list.head) {
    return; // Check if the list is empty before iterating
  }

  // Get the size of the list
  i = coproc_list.ncoproc;

  for (cpe = coproc_list.head; i--;) {
    p = cpe;
    cpe = cpe->next;

    coproc_dispose (p->coproc);
    cpe_dispose (p);

    // Update the size after each iteration
    if (i >= 0)
      cpe = cpe->next;
  }

  coproc_list.head = coproc_list.tail = 0;
  coproc_list.ncoproc = 0;
}