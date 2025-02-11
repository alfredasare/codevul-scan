poolInit(STRING_POOL *pool, const XML_Memory_Handling_Suite *ms) {
 pool->blocks = NULL;
 pool->freeBlocks = NULL;
 pool->start = ms->malloc(1); // Initialize start with a call to malloc
 pool->ptr = pool->start;
 pool->end = pool->start;
 pool->mem = ms;
}