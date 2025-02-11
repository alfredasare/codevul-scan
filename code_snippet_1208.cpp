static inline void *ResizeBlock(void *block, size_t size)
{
  register void *memory;

  if (block == (void *) NULL)
    return(AcquireBlock(size));

  size_t blockSize = SizeOfBlock(block);

  if (size > blockSize - sizeof(size_t))
  {
    error("Invalid size parameter");
    return (void *) NULL;
  }

  memory = AcquireBlock(size);
  if (memory == (void *) NULL)
    return (void *) NULL;

  if (size <= blockSize - sizeof(size_t))
    (void) memcpy_s(memory, blockSize, block, size);
  else
    (void) memcpy_s(memory, blockSize - sizeof(size_t), block, blockSize - sizeof(size_t));

  memory_pool.allocation += size;
  return memory;
}