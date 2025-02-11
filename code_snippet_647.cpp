#include <pthread.h>

void Fail() {
    pthread_mutex_lock(&state_mutex); 
    if (!expect_fail_) {
        FAIL();
    }
    QuitMessageLoop();
    pthread_mutex_unlock(&state_mutex); 
}

pthread_mutex_t state_mutex = PTHREAD_MUTEX_INITIALIZER;