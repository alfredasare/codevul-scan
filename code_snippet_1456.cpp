bool GetErrorQuery::Process() {
  try {
    NOTREACHED();
  } catch (const std::exception& e) {
    LOG(ERROR) << "Exception caught: " << e.what();
    return false;
  }
  return true;
}