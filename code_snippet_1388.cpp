cf2_hintmask_setAll( CF2_HintMask  hintmask,
                     size_t        bitCount )
{
    size_t    i;
    CF2_UInt  mask = ( 1 << ( -(CF2_Int)bitCount & 7 ) ) - 1;

    /* initialize counts and isValid */
    if ( cf2_hintmask_setCounts( hintmask, bitCount ) == 0 )
      return;

    FT_ASSERT( hintmask->byteCount > 0 );
    FT_ASSERT( hintmask->byteCount <
                 sizeof ( hintmask->mask ) / sizeof ( hintmask->mask[0] ) );

    /* set mask to all ones */
    for ( i = 0; i < (size_t)sizeof(hintmask->mask) / sizeof(hintmask->mask[0]); i++ )
    {
        hintmask->mask[i] = 0xFF;
    }

    /* clear unused bits                                              */
    if ( hintmask->byteCount <= (size_t)sizeof(hintmask->mask) / sizeof(hintmask->mask[0]))
        hintmask->mask[hintmask->byteCount - 1] &= ~mask;
}