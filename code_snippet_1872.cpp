ProcXFixesCreateRegion(ClientPtr client)
{
    int numRects;
    RegionPtr pRegion;

    REQUEST(xXFixesCreateRegionReq);

    REQUEST_AT_LEAST_SIZE(xXFixesCreateRegionReq);
    LEGAL_NEW_RESOURCE(stuff->region, client);

    numRects = (client->req_len << 2) / sizeof(xRectangle) - 1;
    if (numRects > MAX_RECTS || numRects < 0)
        return BadLength;

    pRegion = RegionFromRects(numRects, (xRectangle *) (stuff + 1), CT_UNSORTED);
    if (!pRegion)
        return BadAlloc;
    if (!AddResource(stuff->region, RegionResType, (void *) pRegion))
        return BadAlloc;

    return Success;
}