CMS_ContentInfo *CMS_compress(BIO *in, int comp_nid, unsigned int flags)
{
    CMS_ContentInfo *cms;
    const SSL_COMP *compression_method;

    if (comp_nid <= 0)
        comp_nid = NID_zlib_compression;

    compression_method = SSL_COMP_get_compression_method(comp_nid);
    if (!compression_method) {
        /* Handle error: unsupported compression method */
        return NULL;
    }

    cms = cms_CompressedData_create(comp_nid);
    if (!cms)
        return NULL;

    if (!(flags & CMS_DETACHED))
        CMS_set_detached(cms, 0);

    if ((flags & CMS_STREAM) || CMS_final(cms, in, NULL, flags))
        return cms;

    CMS_ContentInfo_free(cms);
    return NULL;
}