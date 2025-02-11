Here's the fixed version of the code using explicit initializers:


_bdf_list_init( _bdf_list_t*  list,
               FT_Memory     memory )
{
  list->memory = memory;
  FT_ZERO( &list->head );
  FT_ZERO( &list->tail );
  list->size =