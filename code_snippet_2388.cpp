String Location::toString() const {
  USVStringOrTrustedURL result;
  String href_value = getHrefValue(); // Get the href value from a trusted source
  if (!isValidHref(href_value)) { // Validate the href value
    result = "Invalid href"; // Set a default value if invalid
  } else {
    href(result); // Safe to call href with validated input
  }
  DCHECK(result.IsUSVString());
  return result.GetAsUSVString();
}

bool Location::isValidHref(const String& href) {
  // Implement your custom validation logic here
  // For example, check if the href starts with a valid scheme (e.g., "http://", "https://")
  return href.startsWith("http://") || href.startsWith("https://");
}