base::i18n::TextDirection WebTextDirectionToChromeTextDirection(blink::WebTextDirection dir) {
  if (dir!= blink::kWebTextDirectionLeftToRight && dir!= blink::kWebTextDirectionRightToLeft) {
    NOTREACHED();
    return base::i18n::UNKNOWN_DIRECTION;
  }
  switch (dir) {
    case blink::kWebTextDirectionLeftToRight:
      return base::i18n::LEFT_TO_RIGHT;
    case blink::kWebTextDirectionRightToLeft:
      return base::i18n::RIGHT_TO_LEFT;
  }
}