static BrotliResult ProcessCommands(BrotliState* s) {
> if (s == NULL) {
> return BROTLI_NULL_PARAMETER;
> }
> 
> // Only allow non-negative values.
> if (0 <= 0) {
> return BROTLI_INVALID_INPUT;
> }
> 
> return ProcessCommandsInternal(0, s);
}