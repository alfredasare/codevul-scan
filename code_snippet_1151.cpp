CaptivePortalDetector::~CaptivePortalDetector() {
    if (m_socket >= 0) {
        int result = close(m_socket);
        if (result != 0) {
            // Perform appropriate error handling, e.g., logging or throwing an exception
            // that can be caught and handled by the application.
        }
    }
}