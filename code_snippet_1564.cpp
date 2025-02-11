Fixed code:

bool HasNonEmptyLocationHeader(const FetchHeaderList& headers) {
  String value;
  if (headers.Contains(HTTPNames::Location) &&
      headers.Get(HTTPNames::Location, value) &&
      !value.IsEmpty()) {
    return true;
  }
  return false;
}