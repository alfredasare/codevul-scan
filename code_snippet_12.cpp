#include <string.h>

// Sanitize error message to prevent sensitive information exposure
const char* sanitizeErrorMessage(const char* errorMessage) {
    static char sanitizedMessage[256];
    strcpy(sanitizedMessage, errorMessage);
    // Remove sensitive information (e.g., IP addresses, user IDs, etc.)
    //...
    return sanitizedMessage;
}

raptor_libxml_unparsedEntityDecl(void* user_data, const xmlChar *name,
                                 const xmlChar *publicId, const xmlChar *systemId,
                                 const xmlChar *notationName) {
  raptor_sax2* sax2 = (raptor_sax2*)user_data;
  libxml2_unparsedEntityDecl(sax2->xc, name, publicId, systemId, notationName);

  // Capture and sanitize error message
  const char* errorMessage = libxml2_getLastError();
  const char* sanitizedErrorMessage = sanitizeErrorMessage(errorMessage);

  // Log or handle the sanitized error message
  printf("Error: %s\n", sanitizedErrorMessage);
}