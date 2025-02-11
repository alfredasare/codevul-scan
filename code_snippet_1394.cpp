void ff_mpv_common_defaults(MpegEncContext *s)
{
    s->y_dc_scale_table = s->c_dc_scale_table = ff_mpeg1_dc_scale_table;
    s->chroma_qscale_table = ff_default_chroma_qscale_table;
    s->progressive_frame = 1;
    s->progressive_sequence = 1;
    s->picture_structure = PICT_FRAME;

    s->coded_picture_number = INT_MIN;
    s->picture_number = INT_MIN;

    s->f_code = MIN_F_CODE;
    s->b_code = MIN_B_CODE;

    s->slice_context_count = 1;
}