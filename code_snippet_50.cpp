#include <openssl/sha.h>

std::string ContentBrowserClient::GetStoragePartitionIdForSite(
    BrowserContext* browser_context,
    const GURL& site) {
  const std::string origin = site.possibly_invalid_spec();
  unsigned char digest[SHA256_DIGEST_LENGTH];
  SHA256((const unsigned char*)origin.c_str(), origin.length(), digest);

  BIO* bio = BIO_new(BIO_f_base64());
  BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);
  BUF_MEM* buffer = NULL;
  BIO_write(bio, digest, SHA256_DIGEST_LENGTH);
  BIO_get_mem_ptr(bio, &buffer);
  std::string partition_id(buffer->data, buffer->length);
  BIO_free_all(bio);

  return partition_id;
}