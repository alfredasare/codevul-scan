ProcRenderReferenceGlyphSet(ClientPtr client)
{
    GlyphSetPtr glyphSet;
    int rc;
    GlyphSetId glyphSetId;

    REQUEST(xRenderReferenceGlyphSetReq);

    REQUEST_SIZE_MATCH(xRenderReferenceGlyphSetReq);

    glyphSetId = stuff->gsid;
    if (glyphSetId < 0 || glyphSetId >= maxGlyphSets || glyphSets[glyphSetId] == NULL) {
        return BadValue;
    }

    rc = dixLookupResourceByType((void **) &glyphSet, stuff->existing,
                                 GlyphSetType, client, DixGetAttrAccess);
    if (rc != Success) {
        client->errorValue = stuff->existing;
        return rc;
    }

    if (glyphSet != glyphSets[glyphSetId]) {
        dixUnlock();
        return BadValue;
    }

    glyphSet->refcnt++;
    return Success;
}