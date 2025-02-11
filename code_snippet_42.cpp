void freerdp_peer_context_new(freerdp_peer* client)
{
    rdpRdp* rdp;
    size_t context_size = client->ContextSize; // validate the input

    // Validate the input size
    if (context_size > MAX_CONTEXT_SIZE) {
        // Handle invalid size
    }

    // Use memalign to allocate memory with proper alignment
    client->context = memalign(16, context_size); // adjust the alignment value as needed
    if (client->context == NULL) {
        // handle allocation failure
    }

    ZeroMemory(client->context, context_size);

    //... rest of the code...
}