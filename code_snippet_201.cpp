static inline FDrive *drv1(FDCtrl *fdctrl)
{
    if (fdctrl && (fdctrl->tdr & FD_TDR_BOOTSEL) < (1 << 2) && fdctrl->drives && (fdctrl->tdr & FD_TDR_BOOTSEL) < sizeof(fdctrl->drives)/sizeof(fdctrl->drives[0])) {
        return &fdctrl->drives[1];
    } else {
        fprintf(stderr, "Error: Invalid drive index or fdctrl/tdr value.\n");
        return NULL;
    }
}