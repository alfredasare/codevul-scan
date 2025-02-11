#include <mutex> /* For std::unique_lock */

/* Add a mutex object to the AMediaCodec structure */
typedef struct AMediaCodec {
    /* Existing members */
    std::mutex lock; /* Mutex for synchronization */
    /* ... */
} AMediaCodec;

/* Initialize the mutex in the constructor */
AMediaCodec::AMediaCodec() {
    /* Existing initialization code */
    /* No need to explicitly initialize std::mutex */
    /* ... */
}

/* Destroy the mutex in the destructor */
AMediaCodec::~AMediaCodec() {
    /* Existing cleanup code */
    /* No need to explicitly destroy std::mutex */
    /* ... */
}

media_status_t AMediaCodec_flush(AMediaCodec *mData) {
    std::unique_lock<std::mutex> lock(mData->lock); /* Lock the mutex before accessing the shared resource */
    media_status_t result = translate_error(mData->mCodec->flush());
    /* Mutex is unlocked automatically when the lock goes out of scope */
    return result;
}