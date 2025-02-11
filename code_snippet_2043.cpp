void RilSapSocket::pushRecord(void *p_record, size_t recordlen) {
    pb_istream_t stream = pb_istream_from_buffer((uint8_t *)p_record, recordlen);
    MsgHeader reqHeader; // Use stack memory instead of malloc
    if (!pb_decode(&stream, MsgHeader_fields, &reqHeader)) {
        RLOGE("Error decoding protobuf buffer : %s", PB_GET_ERROR(&stream));
        return;
    }

    SapSocketRequest recv; // Use stack memory instead of malloc
    recv.token = reqHeader.token;
    recv.curr = &reqHeader;
    recv.socketId = id;

    dispatchQueue.enqueue(&recv);
}