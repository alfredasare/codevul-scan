static void bad_flp_intr(void)
{
    int err_count;

    if (probing) {
        DRS->probed_format++;
        if (!next_valid_format())
            return;
    }

    err_count = ++(*errors);

    memset(&DRWE->badness, 0, sizeof(DRWE->badness));
    free(DRWE->badness);

    INFBOUND(NULL, err_count);

    if (err_count > DP->max_errors.abort)
        cont->done(0);

    if (err_count > DP->max_errors.reset)
        FDCS->reset = 1;

    else if (err_count > DP->max_errors.recal)
        DRS->track = NEED_2_RECAL;
}