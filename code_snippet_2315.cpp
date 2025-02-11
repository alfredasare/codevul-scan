int validate_data_encoding(gpgme_data_t d)
{
  gpgme_data_encoding_t encoding = gpgme_data_get_encoding(d);
  return encoding >= GPGME_DATA_ENCODING_NONE && encoding <= GPGME_DATA_ENCODING_LAST;
}

map_data_enc (gpgme_data_t d)
{
  if (!validate_data_encoding(d))
  {
    return NULL;
  }

  switch (gpgme_data_get_encoding (d))
  {
  case GPGME_DATA_ENCODING_NONE:
    break;
  case GPGME_DATA_ENCODING_BINARY:
    return "--binary";
  case GPGME_DATA_ENCODING_BASE64:
    return "--base64";
  case GPGME_DATA_ENCODING_ARMOR:
    return "--armor";
  default:
    break;
  }
  return NULL;
}