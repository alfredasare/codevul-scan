XineramaTryClientEventsResult(ClientPtr client,
                              GrabPtr grab, Mask mask, Mask filter)
{
    if (!IsValidClient(client) || client == serverClient || client->clientGone) {
        return 0; // Return immediately if client is invalid or gone
    }

    if (!IsValidGrab(grab)) {
        return -1; // Return immediately if grab is invalid
    }

    if (!SameClient(grab, client)) {
        return -1; // Return immediately if grab is not the same client
    }

    if ((filter == CantBeFiltered) || (mask & filter)) {
        return 1;
    }

    return 0;
}