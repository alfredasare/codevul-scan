bool HTMLFormControlElement::reportValidity() {
  HeapVector<Member<HTMLFormControlElement>> unhandledInvalidControls;
  bool isValid = checkValidity(&unhandledInvalidControls,
                               CheckValidityDispatchInvalidEvent);
  if (isValid || unhandledInvalidControls.empty())
    return isValid;
  if (!unhandledInvalidControls.empty()) {
    DCHECK_LT(0u, unhandledInvalidControls.size());
    DCHECK_EQ(unhandledInvalidControls[0].get(), this);
    document().updateStyleAndLayoutIgnorePendingStylesheets();
    if (isFocusable()) {
      showValidationMessage();
      return false;
    }
    if (document().frame()) {
      String message(
          "An invalid form control with name='%name' is not focusable.");
      message.replace("%name", name());
      document().addConsoleMessage(ConsoleMessage::create(
          RenderingMessageSource, ErrorMessageLevel, message));
    }
  }
  return false;
}