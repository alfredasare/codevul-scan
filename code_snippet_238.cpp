url::Component* GetComponent(url::Parsed* parsed, url::Parsed::ComponentType type) {
  switch (type) {
    case url::Parsed::SCHEME:
      return &parsed->scheme;
    case url::Parsed::USERNAME:
      return &parsed->username;
    case url::Parsed::PASSWORD:
      return &parsed->password; // No encoding/sanitization needed for password
    case url::Parsed::HOST:
      return &parsed->host;
    case url::Parsed::PORT:
      return &parsed->port;
    case url::Parsed::PATH:
      return &parsed->path;
    case url::Parsed::QUERY:
      return ESAPI::encodeForHTML(parsed->query); // Sanitize query string
    case url::Parsed::REF:
      return ESAPI::encodeForHTML(parsed->ref); // Sanitize ref attribute
    default:
      NOTREACHED();
      return nullptr;
  }
}