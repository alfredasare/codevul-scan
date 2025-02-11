void MSG_WriteLong(msg_t *sb, int c) {
    uint32_t val = htonl(c);
    MSG_WriteBits(sb, val, sizeof(val) * 8);
}