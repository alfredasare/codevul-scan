ProcXFixesCreateRegion(ClientPtr client)
{
    int things;
    RegionPtr pRegion;

    REQUEST(xXFixesCreateRegionReq);

    REQUEST_AT_LEAST_SIZE(xXFixesCreateRegionReq);
    LEGAL_NEW_RESOURCE(stuff->region, client);

    if (client->req_len < 0 || client->req_len > MAX_REGION_SIZE) {
        return BadLength;
    }

    size_t region_size = sizeof(xXFixesCreateRegionReq) + client->req_len * sizeof(xRectangle);

    pRegion = RegionFromRects(client->req_len, (xRectangle *) (stuff + 1), CT_UNSORTED);
    if (!pRegion) {
        return BadAlloc;
    }
    if (!AddResource(stuff->region, RegionResType, (void *) pRegion)) {
        return BadAlloc;
    }

    return Success;
}