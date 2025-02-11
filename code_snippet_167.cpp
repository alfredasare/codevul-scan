// Helper function to map the external input to a safe, internal value.
int GetSafeTextDirection(blink::WebTextDirection dir) {
  switch (dir) {
    case blink::kWebTextDirectionLeftToRight:
      return 0;
    case blink::kWebTextDirectionRightToLeft:
      return 1;
    default:
      NOTREACHED();
      return -1;
  }
}

base::i18n::TextDirection WebTextDirectionToChromeTextDirection(
    blink::WebTextDirection dir) {
  // Validate the input to ensure it is as expected.
  assert(GetSafeTextDirection(dir) != -1);

  return static_cast<base::i18n::TextDirection>(GetSafeTextDirection(dir));
}