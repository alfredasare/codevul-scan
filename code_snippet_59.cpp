GF_Err tfhd_Read(GF_Box *s, GF_BitStream *bs)
{
    GF_TrackFragmentHeaderBox *ptr = (GF_TrackFragmentHeaderBox *)s;

    ptr->trackID = gf_bs_read_u32(bs);
    if (gf_bs_read_u32(bs) == GF_ERROR) {
        return GF_ERROR;
    }

    if (ptr->flags & GF_ISOM_TRAF_BASE_OFFSET) {
        uint64_t base_offset;
        if (gf_bs_read_u64(bs, &base_offset) == GF_ERROR) {
            return GF_ERROR;
        }
        ptr->base_data_offset = base_offset;
    } else {
        ptr->base_data_offset = 0; // Default to 0 if not present
    }

    if (ptr->flags & GF_ISOM_TRAF_SAMPLE_DESC) {
        uint32_t sample_desc_index;
        if (gf_bs_read_u32(bs, &sample_desc_index) == GF_ERROR) {
            return GF_ERROR;
        }
        ptr->sample_desc_index = sample_desc_index;
    } else {
        ptr->sample_desc_index = 0; // Default to 0 if not present
    }

    if (ptr->flags & GF_ISOM_TRAF_SAMPLE_DUR) {
        uint32_t def_sample_duration;
        if (gf_bs_read_u32(bs, &def_sample_duration) == GF_ERROR) {
            return GF_ERROR;
        }
        ptr->def_sample_duration = def_sample_duration;
    } else {
        ptr->def_sample_duration = 0; // Default to 0 if not present
    }

    if (ptr->flags & GF_ISOM_TRAF_SAMPLE_SIZE) {
        uint32_t def_sample_size;
        if (gf_bs_read_u32(bs, &def_sample_size) == GF_ERROR) {
            return GF_ERROR;
        }
        ptr->def_sample_size = def_sample_size;
    } else {
        ptr->def_sample_size = 0; // Default to 0 if not present
    }

    if (ptr->flags & GF_ISOM_TRAF_SAMPLE_FLAGS) {
        uint32_t def_sample_flags;
        if (gf_bs_read_u32(bs, &def_sample_flags) == GF_ERROR) {
            return GF_ERROR;
        }
        ptr->def_sample_flags = def_sample_flags;
    } else {
        ptr->def_sample_flags = 0; // Default to 0 if not present
    }

    return GF_OK;
}