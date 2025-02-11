static int sd_release(struct gendisk *disk, fmode_t mode)
{
    struct scsi_disk *sdkp = scsi_disk(disk);
    struct scsi_device *sdev = sdkp->device;
    unsigned int removable;

    SCSI_LOG_HLQUEUE(3, sd_printk(KERN_INFO, sdkp, "sd_release\n"));

    removable = sdev->removable; 
    if (atomic_dec_return(&sdkp->openers) == 0 && removable) {
        if (scsi_block_when_processing_errors(sdev))
            scsi_set_medium_removal(sdev, SCSI_REMOVAL_ALLOW);
    }

    scsi_autopm_put_device(sdev);
    scsi_disk_put(sdkp);
    return 0;
}