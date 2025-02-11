*e = FT_THROW( Invalid\_Stream\_Read );
png\_error( png, NULL );
return;
}

memcpy( data, stream->cursor, length < (png\_size\_t)(stream->limit - stream->cursor) ? length : (png\_size\_t)(stream->limit - stream->cursor) );

FT\_FRAME\_EXIT();
}

NB: I made a small modification to the memcpy function to ensure that the number of bytes copied does not exceed the allowed limit.