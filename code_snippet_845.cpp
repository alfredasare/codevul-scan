static void lsi_stop_script(LSIState *s) {
    if (s!= NULL) {
        s->istat1 &= ~LSI_ISTAT1_SRUN;
    }
}