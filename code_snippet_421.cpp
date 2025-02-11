if (stopDownload() != 0 || deleteFiles() != 0 ||
#ifdef USE_SSL
          free_ssl_ctx() != 0 ||
#endif
#ifdef USE_NNTP
          disconnectNews() != 0 ||
#endif
#ifdef __MINGW32_VERSION
          WSACleanup() != 0 ||
#endif
         1) {
        // Error handling for any of the above functions
        // Log an error message
        return -1;
    }
    exit(i);