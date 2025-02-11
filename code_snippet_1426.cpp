static void RelinquishZIPMemory(voidpf context,voidpf memory)
{
  (void) context;
  if (memory!= NULL) {
    memory = RelinquishMagickMemory(memory);
  }
}