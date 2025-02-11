_ksba_cert_get_subject_dn_ptr (ksba_cert_t cert,
                               unsigned char const **ptr, size_t *length)
{
  asn_node_t n;

  if (!cert ||!cert->initialized ||!ptr ||!length)
    return gpg_error (GPG_ERR_INV_VALUE);

  if (*length <= 0) {
    return gpg_error (GPG_ERR_INV_VALUE);
  }

  n = _ksba_asn_find_node (cert->root, "Certificate.tbsCertificate.subject");
  if (!n ||!n->down)
    return gpg_error (GPG_ERR_NO_VALUE); /* oops - should be there */
  n = n->down; /* dereference the choice node */
  if (n->off == -1)
    return gpg_error (GPG_ERR_NO_VALUE);

  unsigned char buf[256]; 
  strncpy(buf, cert->image + n->off, n->len);
  buf[n->len] = '\0';
  *ptr = buf;
  *length = n->nhdr + n->len;
  return 0;
}