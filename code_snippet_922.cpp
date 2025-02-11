PanoramiXRenderChangePicture (ClientPtr client)
{
    PanoramiXRes    *pict = NULL;
    int		    result = Success, j;
    REQUEST(xRenderChangePictureReq);

    REQUEST_AT_LEAST_SIZE(xRenderChangePictureReq);
    
    // Validate pict pointer
    if (!pict ||!IsPanoramiXResValid(pict)) {
        result = Failure;
        goto error;
    }

    // Validate pict structure
    if (!pict->info || pict->numInfo <= 0) {
        result = Failure;
        goto error;
    }

    FOR_NSCREENS_BACKWARD(j) {
        if (j >= pict->numInfo) {
            break; // safe exit
        }
        stuff->picture = pict->info[j].id;
        result = (*PanoramiXSaveRenderVector[X_RenderChangePicture]) (client);
        if(result!= Success) break;
    }

    return result;

error:
    // Handle error condition
    return result;
}