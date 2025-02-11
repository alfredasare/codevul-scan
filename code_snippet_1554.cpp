#include <openssl/rand.h>

virtual void cryptographicallyRandomValues(unsigned char* buffer, size_t length) {
    if (!RAND_bytes(buffer, length)) {
        // Handle error
        // For example, throw an exception or return an error code
    }
}