bool PPResultAndExceptionToNPResult::SetResult(PP_Var result) {
  DCHECK(!checked_exception_);  // Don't call more than once.
  DCHECK(np_result_);  // Should be expecting a result.

  checked_exception_ = true;

  if (has_exception()) {
    ThrowException();
    success_ = false;
  } else if (!IsValidInput(result)) {  
    success_ = false;
  } else if (!PPVarToNPVariant(result, np_result_)) {
    WebBindings::setException(object_var_, kInvalidPluginValue);
    success_ = false;
  } else {
    success_ = true;
  }

  Var::PluginReleasePPVar(result);
  return success_;
}

bool PPResultAndExceptionToNPResult::IsValidInput(PP_Var result) {
  const char* resultStr = PP_VarToJSONString(result);
  if (strchr(resultStr, '/') || strchr(resultStr, '\\') || strchr(resultStr, '..') || strchr(resultStr, '~')) {
    return false;  // Input contains path traversal characters
  }
  return true;  // Input is valid
}