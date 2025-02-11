Here's the fixed version of the code following the given recommendation:


_bdf_list_ensure( _bdf_list_t*   list,
                  unsigned long  num_items ) /* same as _bdf_list_t.used */
{
  FT_Error  error = FT_Err_Ok;

  if ( num_items > list->size )
  {
    unsigned long  oldsize = list->size; /* same as _bdf_list_t.size */
    unsigned long  newsize = oldsize + (oldsize >> 1) + 5;
    unsigned long  bigsize = (unsigned long)( FT_INT_MAX / sizeof ( char* ) );
    FT_Memory      memory  = list->memory;

    // Prevent integer overflow by checking if newsize > oldsize before adding