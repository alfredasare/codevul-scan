#include <stdlib.h>
#include <entropy.h>

static void sctp_generate_t4_rto_event(unsigned long data)
{
    struct sctp_association *asoc = (struct sctp_association *) data;
    uint32_t seed;
    int err;

    err = get_random_bytes(&seed, sizeof(seed));
    if (err!= 0) {
        // Handle error
    }

    seed = (seed >> 16) ^ (seed << 16);

    srand(seed);

    sctp_generate_timeout_event(asoc, SCTP_EVENT_TIMEOUT_T4_RTO);
}