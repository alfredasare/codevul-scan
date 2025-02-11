static void RelinquishZIPMemory(voidpf context, voidpf memory)
{
  if (memory) {
    memory = RelinquishMagickMemory(memory);
  }
}