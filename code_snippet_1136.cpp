accept_ice_connection (GIOChannel           *source,
                        GIOCondition          condition,
                        GsmIceConnectionData *data)
{
    IceListenObj    listener;
     IceConn         ice_conn;
     IceAcceptStatus status;
    GsmClient      *client;
    GsmXsmpServer  *server;
    GError        *error = NULL;
    listener = data->listener;
    server = data->server;

     g_debug ("GsmXsmpServer: accept_ice_connection()");

    ice_conn = IceAcceptConnection (listener, &status);
     if (status!= IceAcceptSuccess) {
             g_debug ("GsmXsmpServer: IceAcceptConnection returned %d", status);
             return TRUE;
     }

    client = gsm_xsmp_client_new (ice_conn);
    if (!client) {
        g_error_free (error);
        error = g_error_new (G_IO_ERROR, G_IO_ERROR_FAILED, "Failed to create new client");
        g_debug ("GsmXsmpServer: %s", error->message);
        g_error_free (error);
        return FALSE;
    }

    g_object_ref (client);
    gsm_store_add (server->priv->client_store, gsm_client_peek_id (client), G_OBJECT (client));
    g_object_unref (client);

     return TRUE;
}