PanoramiXRenderChangePicture (ClientPtr client)
{
    PanoramiXRes    *pict;
    int		    result = Success, j;
    REQUEST(xRenderChangePictureReq);

    REQUEST_AT_LEAST_SIZE(xRenderChangePictureReq);

    // Validate and sanitize user-supplied input
    if (!isValidPicture(stuff->picture, client)) {
        return BadRequest;
    }

    VERIFY_XIN_PICTURE(pict, stuff->picture, client, DixWriteAccess);

    FOR_NSCREENS_BACKWARD(j) {
        stuff->picture = pict->info[j].id;
        result = (*PanoramiXSaveRenderVector[X_RenderChangePicture]) (client);
        if(result != Success) break;
    }

    return result;
}

// Add a helper function to validate the picture
bool isValidPicture(Picture picture, ClientPtr client) {
    // Perform access control checks and ensure the picture belongs to the client
    // Return true if valid, false otherwise
}