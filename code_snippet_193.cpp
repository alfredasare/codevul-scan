static BROTLI_NOINLINE BrotliResult ProcessCommands(BrotliState* s) {
  int size = s->input_size; 
  if (size > s->buffer_size) { 
    return BrotliError(BROTLI_ERROR_INVALID_INPUT_SIZE);
  }
  memcpy_s(s->buffer, s->buffer_size, s->input, size);
  // Rest of the code...
}