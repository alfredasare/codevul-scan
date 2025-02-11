#include <openssl/rand.h>

CMS_ContentInfo *CMS_compress(BIO *in, int comp_nid, unsigned int flags)
{
    CMS_ContentInfo *cms;
    unsigned char rand_data[16]; // adjust the size according to your requirements
    int ret;

    if (comp_nid <= 0)
        comp_nid = NID_zlib_compression;

    // Generate a cryptographically secure random number
    ret = RAND_bytes(rand_data, sizeof(rand_data));
    if (!ret)
        return NULL;

    // Convert the random data to an integer
    comp_nid = *(int *)rand_data;

    cms = cms_CompressedData_create(comp_nid);
    if (!cms)
        return NULL;

    if(!(flags & CMS_DETACHED))
        CMS_set_detached(cms, 0);

    if ((flags & CMS_STREAM) || CMS_final(cms, in, NULL, flags))
        return cms;

    CMS_ContentInfo_free(cms);
    return NULL;
}