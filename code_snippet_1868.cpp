RTCPeerConnectionHandler::RTCPeerConnectionHandler()
{
    // Validate and sanitize user input
    if (strlen(user_input) > MAX_INPUT_LENGTH) {
        throw std::runtime_error("Input too long");
    }

    // Allocate memory for the input data
    char* buffer = new char[strlen(user_input) + 1];
    std::strcpy(buffer, user_input);

    // Use the validated and sanitized input data
    //...

    // Delete the allocated memory
    delete[] buffer;
}