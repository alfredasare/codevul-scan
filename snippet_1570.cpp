DGAGetOldDGAMode(int index)
{
    DGAScreenPtr pScreenPriv = DGA_GET_SCREEN_PRIV(screenInfo.screens[index]);
    ScrnInfoPtr pScrn = pScreenPriv->pScrn;
    DGAModePtr mode;
    int i, w, h, p;

    /* We rely on the extension to check that DGA is available */

    w = pScrn->currentMode->HDisplay;
    h = pScrn->currentMode->VDisplay;
    p = pad_to_int32(pScrn->displayWidth * bits_to_bytes(pScrn->bitsPerPixel));

    for (i = 0; i < pScreenPriv->numModes; i++) {
        mode = &(pScreenPriv->modes[i]);

        if ((mode->viewportWidth == w) && (mode->viewportHeight == h) &&
            (mode->bytesPerScanline == p) &&
            (mode->bitsPerPixel == pScrn->bitsPerPixel) &&
            (mode->depth == pScrn->depth)) {

            return mode->num;
        }
    }

    return 0;
}
