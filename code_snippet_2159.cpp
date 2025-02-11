static volatile sig_atomic_t running = 1;

void handle_signal(int signo)
{
    (void)signo;
    running = 0;
}

static void exit_handler(int signo)
{
    if (running != 0) {
        (void)signo;
        running = 0;
    }
}