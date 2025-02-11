SMB2_sess_establish_session(struct SMB2_sess_data *sess_data)
{
    //...
    if (!ses->server->session_estab) {
        uint64_t sequence_number = 0x2;
        ses->server->sequence_number = sequence_number;
        ses->server->session_estab = true;
    }
    //...
}