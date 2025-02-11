static void ssl_write_supported_point_formats_ext( mbedtls_ssl_context *ssl,
                                               unsigned char *buf,
                                               size_t *olen )
{
    unsigned char *p = buf;
    ((void) ssl);

    if( ( ssl->handshake->cli_exts &
          MBEDTLS_TLS_EXT_SUPPORTED_POINT_FORMATS_PRESENT ) == 0 )
    {
        *olen = 0;
        return;
    }

    MBEDTLS_SSL_DEBUG_MSG( 3, ( "server hello, supported_point_formats extension" ) );

    uint16_t supportedPointFormats = MBEDTLS_TLS_EXT_SUPPORTED_POINT_FORMATS;
    if( supportedPointFormats > 0xFFFF )
    {
        supportedPointFormats = 0xFFFF; // or handle the error/exception
    }

    *p++ = (unsigned char)( ( supportedPointFormats >> 8 ) & 0xFF );
    *p++ = (unsigned char)( supportedPointFormats & 0xFF );

    *p++ = 0x00;
    *p++ = 2;

    *p++ = 1;
    *p++ = MBEDTLS_ECP_PF_UNCOMPRESSED;

    *olen = 6;
}