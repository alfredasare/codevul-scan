ses->server->sequence_number = 0x2;
ses->server->session_estab = true;
}
mutex_unlock(&ses->server->srv_mutex);

cifs\_dbg(FYI, "SMB2/3 session established successfully\n");
spin\_lock(&GlobalMid\_Lock);
ses->status = CifsGood;
ses->need\_reconnect = false;
spin\_unlock(&GlobalMid\_Lock);
keygen\_exit:
if (!ses->server->sign) {
kfree(ses->auth\_key.response);
ses->auth\_key.response = NULL;
}
return rc;
}

int isValidSigningKey(const void\* key) {
// Implement key validation logic here
// ...
}