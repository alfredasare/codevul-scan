NTSTATUS smb1cli\_session\_set\_session\_key(struct smbXcli\_session \*session,
const DATA\_BLOB \_session\_key)
{
 struct smbXcli\_conn \*conn = session->conn;
 uint8\_t session\_key[16];

 if (conn == NULL) {
 return NT\_STATUS\_INVALID\_PARAMETER\_MIX;
 }

 if (session->smb1.application\_key.length != 0) {
 // Validate input properly
 if (\_session\_key.length != 16) {
 return NT\_STATUS\_INVALID\_PARAMETER;
 }

 data\_blob\_clear\_free(&session->smb1.application\_key);
 session->smb1.protected\_key = false;
 }

 if (\_session\_key.length == 0) {
 return NT\_STATUS\_OK;
 }

 ZERO\_STRUCT(session\_key);
 memcpy(session\_key, \_session\_key.data,
 MIN(\_session\_key.length, sizeof(session\_key)));

 session->smb1.application\_key = data\_blob\_talloc(session,
 session\_key,
 sizeof(session\_key));
 ZERO\_STRUCT(session\_key);
 if (session->smb1.application\_key.data == NULL) {
 return NT\_STATUS\_NO\_MEMORY;
 }

 session->smb1.protected\_key = false;

 return NT\_STATUS\_OK;
}