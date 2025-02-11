SetClientPointer(ClientPtr client, DeviceIntPtr device)
{
    int rc = XaceHook(XACE_DEVICE_ACCESS, client, device, DixUseAccess);

    if (rc!= Success)
        return rc;

    // Validate device ID
    if (device->id < 0 || device->id >= MAX_DEVICES) {
        ErrorF("[dix] Invalid device ID %d\n", device->id);
        return BadDevice;
    }

    // Check if device is in the whitelist
    if (!isAllowedDevice(device->id)) {
        ErrorF("[dix] Device %d is not allowed\n", device->id);
        return BadDevice;
    }

    if (!IsMaster(device)) {
        ErrorF("[dix] Need master device for ClientPointer. This is a bug.\n");
        return BadDevice;
    }
    else if (!device->spriteInfo->spriteOwner) {
        ErrorF("[dix] Device %d does not have a sprite. Cannot be ClientPointer\n", device->id);
        return BadDevice;
    }
    client->clientPtr = device;
    return Success;
}

bool isAllowedDevice(int deviceId) {
    // Load the whitelist from a secure data storage mechanism
    FILE *fp = fopen("/path/to/whitelist.txt", "r");
    if (fp == NULL) {
        return false;
    }

    while (fgets(line, sizeof(line), fp)) {
        char *token = strtok(line, ":");
        if (atoi(token) == deviceId) {
            fclose(fp);
            return true;
        }
    }
    fclose(fp);
    return false;
}