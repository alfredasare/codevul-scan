ProcListFonts(ClientPtr client)
{
    REQUEST(xListFontsReq);

    if (!stuff) {
        ErrorF("stuff is null\n");
        return;
    }

    REQUEST_FIXED_SIZE(xListFontsReq, stuff->nbytes);

    return ListFonts(client, (unsigned char *) &stuff[1], stuff->nbytes, stuff->maxNames);
}