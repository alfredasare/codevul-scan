void HTMLFormControlElement::Reset() {
  switch (WebAutofillState::kNotFilled) {
    case WebAutofillState::kNotFilled:
      SetAutofillState(WebAutofillState::kNotFilled);
      ResetImpl();
      break;
    default:
      break; // add default case to handle other possible values
  }
}