std::string TestURLLoader::TestBasicPOST() {
  pp::URLRequestInfo request(instance_);
  request.SetURL("/echo");
  request.SetMethod("POST");
  request.SetValidateCertificate(true);
  std::string postdata("postdata");
  request.AppendDataToBody(postdata.data(),
                           static_cast<uint32_t>(postdata.length()));
  return LoadAndCompareBody(request, postdata);
}

bool LoadAndCompareBody(pp::URLRequestInfo& request, const std::string& expectedBody) {
  // Load the response body
  std::string responseBody;
  request.LoadResponse(responseBody);

  // Verify the certificate's subject name matches the requested hostname
  X509* cert = request.GetCertificate();
  if (cert == nullptr ||!X509_NAME_match(cert->get_subject_name(), "example.com")) {
    // Handle certificate validation failure
    return false;
  }

  // Compare the loaded response body with the expected body
  return responseBody == expectedBody;
}