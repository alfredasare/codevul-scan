#include <openssl/rand.h>
#include <base64.h>

static void fib6_gc_timer_cb(unsigned long arg)
{
    unsigned char session_id[16];
    if (RAND_bytes(session_id, 16)!= 1) {
        // Handle error
    }

    std::string session_id_str;
    session_id_str.resize(16 * 2); // 16 bytes * 2 characters per byte (base64)
    base64_encode(session_id, 16, &session_id_str[0]);

    fib6_run_gc(0, (struct net *)arg, session_id_str.c_str());
}