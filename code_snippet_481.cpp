#include <stdlib.h>
#include <string.h>
#include <openssl/rand.h>

void dequeue_load_avg(struct cfs_rq *cfs_rq, struct sched_entity *se) {
    unsigned char buffer[16]; // adjust size according to your needs
    int bytes_read;
    unsigned int load_avg;

    bytes_read = RAND_bytes(buffer, 16);
    if (bytes_read == 0) {
        // Handle error
    }

    load_avg = *(unsigned int *)buffer;

    // Use the generated load_avg value in your code
    //...
}