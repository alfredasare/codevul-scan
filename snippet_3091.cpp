WORD32 ihevcd_parse_part_mode_amp(cab_ctxt_t *ps_cabac, bitstrm_t *ps_bitstrm)
{
    WORD32 ctxt_idx = IHEVC_CAB_PART_MODE;
    WORD32 part_mode_idx;
    WORD32 part_mode;
    WORD32 bin;

    part_mode = 0;
    TRACE_CABAC_CTXT("part_mode", ps_cabac->u4_range, ctxt_idx);
    bin = ihevcd_cabac_decode_bin(ps_cabac, ps_bitstrm, ctxt_idx++);

 if(!bin)
 {
        bin = ihevcd_cabac_decode_bin(ps_cabac, ps_bitstrm, ctxt_idx++);
        part_mode_idx = bin;
        part_mode_idx <<= 1;

 /* Following takes of handling context increment for 3rd bin in part_mode */
 /* When AMP is enabled and the current is not min CB */
 /* Context for 3rd bin is 3 and not 2 */
        ctxt_idx += 1;

        bin = ihevcd_cabac_decode_bin(ps_cabac, ps_bitstrm, ctxt_idx);
        part_mode_idx |= bin;

        part_mode_idx <<= 1;
 if(!bin)
 {

            bin = ihevcd_cabac_decode_bypass_bin(ps_cabac, ps_bitstrm);
            part_mode_idx |= bin;
 }
        part_mode = gau1_part_mode_amp[part_mode_idx];
 }
 return part_mode;
}
