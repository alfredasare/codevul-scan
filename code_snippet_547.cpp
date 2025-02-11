void cf2_getFamilyOtherBlues( CFF_Decoder*  decoder,
                               size_t*       count,
                               FT_Pos*      *data )
{
    if (!decoder ||!decoder->current_subfont) {
        return;
    }

    *count = decoder->current_subfont->private_dict.num_family_other_blues;
    *data  = (FT_Pos*) &decoder->current_subfont->private_dict.family_other_blues;
}