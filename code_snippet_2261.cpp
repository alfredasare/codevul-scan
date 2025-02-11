static int poll_drive(bool interruptible, int flag)
{
    /* no auto-sense, just clear dcl */
    raw_cmd = &default_raw_cmd;
    if (flag < 0 || flag > RAW_CMD_MAX_FLAGS) {
        return -EINVAL;
    }
    raw_cmd->flags = flag & RAW_CMD_VALID_FLAGS;
    raw_cmd->track = 0;
    raw_cmd->cmd_count = 0;
    cont = &poll_cont;
    debug_dcl(DP->flags, "setting NEWCHANGE in poll_drive\n");
    set_bit(FD_DISK_NEWCHANGE_BIT, &DRS->flags);

    return wait_til_done(floppy_ready, interruptible);
}