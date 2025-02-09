int yr_arena_reserve_memory(
    YR_ARENA* arena,
    size_t size)
{
  YR_ARENA_PAGE* new_page;
  size_t new_page_size;
  uint8_t* new_page_address;

  if (size > free_space(arena->current_page))
  {
    if (arena->flags & ARENA_FLAGS_FIXED_SIZE)
      return ERROR_INSUFFICIENT_MEMORY;


    new_page_size = arena->current_page->size * 2;

    while (new_page_size < size)
      new_page_size *= 2;

    if (arena->current_page->used == 0)
    {

      new_page_address = (uint8_t*) yr_realloc(
          arena->current_page->address,
          new_page_size);

      if (new_page_address == NULL)
        return ERROR_INSUFFICIENT_MEMORY;

      arena->current_page->address = new_page_address;
      arena->current_page->size = new_page_size;
    }
    else
    {
      new_page = _yr_arena_new_page(new_page_size);

      if (new_page == NULL)
        return ERROR_INSUFFICIENT_MEMORY;

      new_page->prev = arena->current_page;
      arena->current_page->next = new_page;
      arena->current_page = new_page;
      arena->flags &= ~ARENA_FLAGS_COALESCED;
    }
  }

  return ERROR_SUCCESS;
}
