#include <pthread.h>

static pthread_mutex_t m_lock = PTHREAD_MUTEX_INITIALIZER;

static void pmac_ide_flush(DBDMA_io *io)
{
    MACIOIDEState *m = io->opaque;

    pthread_mutex_lock(&m_lock);
    if (m->aiocb) {
        blk_drain_all();
    }
    pthread_mutex_unlock(&m_lock);
}