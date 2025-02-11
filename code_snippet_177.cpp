ProcRenderReferenceGlyphSet(ClientPtr client)
{
    GlyphSetPtr glyphSet;
    int rc;

    REQUEST(xRenderReferenceGlyphSetReq);

    REQUEST_SIZE_MATCH(xRenderReferenceGlyphSetReq);

    LEGAL_NEW_RESOURCE(stuff->gsid, client);

    // Validate input parameter
    if (stuff->existing < 0 || stuff->existing >= NUM_GLYPHSETS) {
        client->errorValue = stuff->existing;
        return BadValue;
    }

    rc = dixLookupResourceByType((void **) &glyphSet, stuff->existing,
                                 GlyphSetType, client, DixGetAttrAccess);
    if (rc!= Success) {
        return rc;
    }
    glyphSet->refcnt++;
    if (!AddResource(stuff->gsid, GlyphSetType, (void *) glyphSet))
        return BadAlloc;
    return Success;
}