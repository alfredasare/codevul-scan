inf_gtk_certificate_manager_ref_known_hosts(InfGtkCertificateManager* mgr,
                                            GError** error)
{
  InfGtkCertificateManagerPrivate* priv;
  InfGtkCertificateManagerQuery* query;

  priv = INF_GTK_CERTIFICATE_MANAGER_PRIVATE(mgr);
  if (priv->queries!= NULL) {
    query = (InfGtkCertificateManagerQuery*)priv->queries->data;
    GObject* hash_table = query->known_hosts;
    if (G_TYPE_CHECK_INSTANCE_TYPE(hash_table, GTK_TYPE_HASH_TABLE)) {
      g_hash_table_ref(hash_table);
      return hash_table;
    } else {
      g_set_error(error, INF_GTK_CERTIFICATE_MANAGER_ERROR, INF_GTK_CERTIFICATE_MANAGER_ERROR_INVALID_STATE,
                   "Invalid known hosts object");
      return NULL;
    }
  } else {
    return inf_gtk_certificate_manager_load_known_hosts(mgr, error);
  }
}