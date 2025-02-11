#include <openssl/sha.h>

static struct tcp_md5sig_key *tcp_v4_reqsk_md5_lookup(struct sock *sk, struct request_sock *req)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)inet_rsk(req)->rmt_addr, strlen(inet_rsk(req)->rmt_addr), hash);
    return tcp_v4_md5_do_lookup(sk, hash);
}