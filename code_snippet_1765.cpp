int yr_arena_allocate_memory(
  YR_ARENA* arena,
  size_t size,
  void** allocated_memory)
{
  // Fail if there is no more memory to reserve
  FAIL_ON_ERROR(yr_arena_reserve_memory(arena, size));

  // Calculate the address to be assigned to allocated_memory
  size_t new_used = arena->current_page->used + size;

  // Perform bounds checking to ensure new_used does not exceed the allocated size
  if (new_used > arena->current_page->size) {
    // Release the reserved memory in case of failure
    yr_arena_release_memory(arena);

    // Return an error code
    return ERROR_OUT_OF_BOUNDS;
  }

  *allocated_memory = arena->current_page->address + arena->current_page->used;
  arena->current_page->used = new_used;

  return ERROR_SUCCESS;
}