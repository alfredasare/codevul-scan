_ksba_cert_get_subject_dn_ptr (ksba_cert_t cert,
                               unsigned char const **ptr, size_t *length)
{
  asn_node_t n;

  if (!cert || !cert->initialized || !ptr || !length)
    return gpg_error (GPG_ERR_INV_VALUE);

  if (!cert->image)
    return gpg_error (GPG_ERR_INV_VALUE);

  n = _ksba_asn_find_node (cert->root, "Certificate.tbsCertificate.subject");
  if (!n || !n->down)
    return gpg_error (GPG_ERR_NO_VALUE);

  n = n->down;
  if (n->off == -1)
    return gpg_error (GPG_ERR_NO_VALUE);

  if (cert->image_size < n->nhdr + n->len)
    return gpg_error (GPG_ERR_BAD_DATA);

  *ptr = cert->image + n->off;
  *length = n->nhdr + n->len;
  return 0;
}