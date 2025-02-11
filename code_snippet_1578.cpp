void ntlm_write_message_fields(wStream* s, NTLM_MESSAGE_FIELDS* fields)
{
    if (fields == NULL || fields->MaxLen < 0) {
        return;
    }

    if (fields->MaxLen > MAX_VALID_MAXLEN) {
        fields->MaxLen = MAX_VALID_MAXLEN;
    }

    if (fields->Len > fields->MaxLen || fields->BufferOffset > fields->MaxLen) {
        // Handle out-of-bounds values
        return;
    }

    Stream_Write_UINT16(s, fields->Len); 
    Stream_Write_UINT16(s, fields->MaxLen); 
    Stream_Write_UINT32(s, fields->BufferOffset); 
}