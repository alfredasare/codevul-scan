bool PPResultAndExceptionToNPResult::SetResult(PP_Var result) {
  DCHECK(!checked_exception_);  // Don't call more than once.
  DCHECK(np_result_);  // Should be expecting a result.

  if (!IsValidPPVar(result)) {
    WebBindings::setException(object_var_, kInvalidPluginValue);
    return false;
  }

  checked_exception_ = true;

  if (has_exception()) {
    ThrowException();
    return false;
  } else if (!PPVarToNPVariant(result, np_result_)) {
    WebBindings::setException(object_var_, kInvalidPluginValue);
    return false;
  } else {
    return true;
  }

  Var::PluginReleasePPVar(result);
}

bool PPResultAndExceptionToNPResult::IsValidPPVar(PP_Var var) {
  // Add your validation logic here.
  // For example:
  // return var->type == PP_VARTYPE_STRING && var->value.string->length < 1024;
}