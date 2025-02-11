void ff_mpv_common_defaults(MpegEncContext *s)
{
    s->y_dc_scale_table = malloc( sizeof(float) * DC_SCALES );
    s->c_dc_scale_table = malloc( sizeof(float) * DC_SCALES );
    s->chroma_qscale_table = malloc( sizeof(int) * 2 * MAX_Q );

    if (!s->y_dc_scale_table ||!s->c_dc_scale_table ||!s->chroma_qscale_table) {
        fprintf(stderr, "Error allocating memory for tables\n");
        return;
    }

    s->y_dc_scale_table      = ff_mpeg1_dc_scale_table;
    s->c_dc_scale_table      = ff_mpeg1_dc_scale_table;
    s->chroma_qscale_table   = ff_default_chroma_qscale_table;
    //... rest of the code...
}