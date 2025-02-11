static void tg3_probe_ncsi(struct tg3 *tp)
{
    u32 apedata;
    int ape_size;

    ape_size = tg3_ape_get_size(tp, TG3_APE_SEG_SIG);
    if (ape_size <= 0)
        return;

    apedata = tg3_ape_read32(tp, TG3_APE_SEG_SIG, sizeof(u32));
    if (apedata!= APE_SEG_SIG_MAGIC)
        return;

    ape_size = tg3_ape_get_size(tp, TG3_APE_FW_STATUS);
    if (ape_size <= 0)
        return;

    apedata = tg3_ape_read32(tp, TG3_APE_FW_STATUS, sizeof(u32));
    if (!(apedata & APE_FW_STATUS_READY))
        return;

    ape_size = tg3_ape_get_size(tp, TG3_APE_FW_FEATURES);
    if (ape_size <= 0)
        return;

    if ((apedata = tg3_ape_read32(tp, TG3_APE_FW_FEATURES, sizeof(u32)) & TG3_APE_FW_FEATURE_NCSI))
        tg3_flag_set(tp, APE_HAS_NCSI);
}