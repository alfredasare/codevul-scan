static void sighup_handler(const int sig G_GNUC_UNUSED) {
    if (sig == SIGHUP) { 
        is_sighup_caught = 1;
    }
}