static int jpc_sot_dumpparms(jpc_ms_t *ms, FILE *out)
{
    jpc_sot_t *sot = &ms->parms.sot;
    if (sot != NULL) {
        fprintf(out, "tileno = %d; len = %d; partno = %d; numparts = %d\n",
          sot->tileno, sot->len, sot->partno, sot->numparts);
    } else {
        fprintf(stderr, "Error: sot pointer is null\n");
        return -1;
    }
    return 0;
}