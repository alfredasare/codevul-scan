#include <signal.h>
#include <stdbool.h>

static volatile sig_atomic_t is_sighup_caught = 0;

/* Signal handler that sets the local variable */
static void sighup_handler(const int s G_GNUC_UNUSED) {
    is_sighup_caught = 1;
}

/* Function to perform required operation with the local variable */
void handle_sighup(void) {
    sig_atomic_t local_sighup_caught = is_sighup_caught;
    if (local_sighup_caught) {
        // Perform the necessary operation here
    }
}