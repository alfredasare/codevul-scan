#include <pthread.h>

pthread_mutex_t client_mutex = PTHREAD_MUTEX_INITIALIZER;

mainloop_del_fd(mainloop_io_t *client)
{
    if(client != NULL) {
        pthread_mutex_lock(&client_mutex); // Acquire the lock
        crm_trace("Removing client %s[%p] %d", client->name, client, mainloop_gio_refcount(client));
        if (client->source) {
            /* Results in mainloop_gio_destroy() being called just
             * before the source is removed from mainloop
             */
            g_source_remove(client->source);
            client->source = NULL; // Reset the source to avoid use-after-free
        }
        pthread_mutex_unlock(&client_mutex); // Release the lock
    }
}