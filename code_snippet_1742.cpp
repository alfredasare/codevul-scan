Stream_Write_UINT16(s, fields->Len);      /* Len (2 bytes) */
Stream_Write_UINT16(s, fields->MaxLen);   /* MaxLen (2 bytes) */
Stream_Write_UINT32(s, fields->BufferOffset); /* BufferOffset (4 bytes) */