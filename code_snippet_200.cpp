static inline FDrive *drv1(FDCtrl *fdctrl)
{
    int idx = (fdctrl->tdr & FD_TDR_BOOTSEL) >> 2;
    if (idx < 0 || idx >= fdctrl->num_drives) {
        return NULL;
    }
    return &fdctrl->drives[idx];
}