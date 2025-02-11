void switch_bench(u32 is_on)
{
    if (is_on < 0 || is_on > 1) {
        return;
    }

    bench_mode = is_on;
    display_rti = is_on? 2 : 0;
    ResetCaption();

    char buffer[64];
    snprintf(buffer, sizeof(buffer), "GF_OPT_VIDEO_BENCH=%u", is_on);
    gf_term_set_option(term, buffer);
}