void cleanup_exit(int i) {
    cleanup_socket();
    exit(i);
}