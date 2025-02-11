ProcListFonts(ClientPtr client)
{
    REQUEST(xListFontsReq);

    REQUEST_FIXED_SIZE(xListFontsReq, stuff->nbytes);

    const int max_allowed_bytes = 1024; // Set a maximum limit suitable for your application
    if (stuff->nbytes > max_allowed_bytes) {
        stuff->nbytes = max_allowed_bytes;
    }

    return ListFonts(client, (unsigned char *) &stuff[1], stuff->nbytes,
                     stuff->maxNames);
}