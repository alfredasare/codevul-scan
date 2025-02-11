#include <esapi.h>

void ip_flush_pending_frames(struct sock *sk)
{
    char *sanitized_base = esapi_validateString(inet_sk(sk)->cork.base, ESAPI_VALIDATION_ALLOW_ONLY_ALPHANUMERIC);
    __ip_flush_pending_frames(sk, &sk->sk_write_queue, sanitized_base);
}