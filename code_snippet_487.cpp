const std::set<std::string> kAllowedMethods = {"POST"};

std::string TestURLLoader::TestBasicPOST() {
  pp::URLRequestInfo request(instance_);
  request.SetURL("/echo");

  // Check if the request method is in the allowed methods set
  if (kAllowedMethods.find(request.GetMethod()) == kAllowedMethods.end()) {
    throw std::invalid_argument("Invalid request method. Allowed: POST.");
  }

  // Set the request method to POST, as it has been validated
  request.SetMethod("POST");
  std::string postdata("postdata");
  request.AppendDataToBody(postdata.data(),
                           static_cast<uint32_t>(postdata.length()));
  return LoadAndCompareBody(request, postdata);
}