++
bool HasNonEmptyLocationHeader(const FetchHeaderList* headers) {
  String value;
  if (headers->Get(HTTPNames::Location, value)) {
    return!value.IsEmpty();
  } else {
    return false;
  }
}