int Curl_nss_random(struct Curl_easy *data,
                    unsigned char *entropy,
                    size_t length)
{
  Curl_nss_seed(data);  /* Initiate the seed if not already done */

  SECStatus status = PK11_GenerateRandom(entropy, length);
  if (status!= SECSuccess) {
    return -1;
  }

  if (length!= crypto_rand_bytes_length(entropy)) {
    return -1;
  }

  return 0;
}