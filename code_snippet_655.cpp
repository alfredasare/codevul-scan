std::unique_ptr<net::test_server::HttpResponse> HandleMockResource(
    const net::test_server::HttpRequest& request) {
  // Normalize the path to ensure proper input validation
  std::string normalized_path = absl::StripLeadingAndTrailing(
      request.GetURL().path(), "/..");

  if (normalized_path.empty() || normalized_path[0] == '/') {