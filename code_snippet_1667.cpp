// Define a constant for the socket ID
#define SOCKET_ID 12345

typedef struct {
    // ... other socket properties ...
    int id;
} asocket;

void connect_to_smartsocket(asocket* s) {
    D("Connecting to smart socket");
    asocket* ss = create_smart_socket();
    ss->id = SOCKET_ID; // Set a common ID for both sockets
    s->id = SOCKET_ID; // Set the same ID for the original socket
    s->ready(s);
}

// Use this function to check if two sockets are connected
bool are_sockets_connected(asocket* s1, asocket* s2) {
    return s1->id == s2->id; // Compare their IDs to determine connection
}