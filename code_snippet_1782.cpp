#include <openssl/sha.h>

void RunTransactionTestWithResponse(net::HttpCache* cache,
                                  const MockTransaction& trans_info,
                                  std::string* response_headers) {
    net::HttpResponseInfo response;
    RunTransactionTestWithResponseInfo(cache, trans_info, &response);

    // Generate a secure session ID using OpenSSL
    unsigned char session_id[32];
    SHA256((const unsigned char*)trans_info.c_str(), trans_info.size(), session_id);

    // Convert the session ID to a string
    std::string session_id_str(reinterpret_cast<const char*>(session_id), 32);

    response.headers->GetNormalizedHeaders(response_headers);

    // Store the secure session ID
    cache->SetSessionId(session_id_str);
}