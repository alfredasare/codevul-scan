code:


static GF_StreamContext *gf_sm_get_stream(GF_SceneManager *ctx, u16 ESID)
{
    const u16 allowed_ESIDs[] = {0, 1, 2, 3, /* Add more allowed ESID values */};
    u32 i, count;

    count = gf_list_count(ctx->streams);
    for (i=0; i<count; i++) {
        GF_StreamContext *sc = gf_list_get(ctx->streams, i);
        if (find_element_in_array(allowed_ESIDs, sizeof(allowed_ESIDs)/sizeof(allowed_ESIDs[0]), sc->ESID)) {
            return sc;
        }
    }

    return NULL;
}

bool find_element_in_array(const u16* arr, u32 size, u16 target)
{
    for (u32 i=0; i<size; i++) {
        if (arr[i] == target) {
            return true;
        }
    }
    return false;
}