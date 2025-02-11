SetClientPointer(ClientPtr client, DeviceIntPtr device)
{
    // Validate inputs
    if (!client || !device) {
        ErrorF("Invalid pointer passed to SetClientPointer\n");
        return BadValue;
    }

    int rc = XaceHook(XACE_DEVICE_ACCESS, client, device, DixUseAccess);

    if (rc != Success)
        return rc;

    if (!IsMaster(device) || !device->spriteInfo || !device->spriteInfo->spriteOwner) {
        if (!IsMaster(device))
            ErrorF("[dix] Need master device for ClientPointer. This is a bug.\n");
        if (!device->spriteInfo || !device->spriteInfo->spriteOwner)
            ErrorF("[dix] Device %d does not have a sprite. "
                   "Cannot be ClientPointer\n", device->id);
        return BadDevice;
    }
    client->clientPtr = device;
    return Success;
}