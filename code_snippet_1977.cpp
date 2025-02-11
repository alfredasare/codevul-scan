struct scsi\_disk {
`...`
spinlock\_t openers\_lock;
`...`
};

static int sd\_release(struct gendisk \*disk, fmode\_t mode)
{
struct scsi\_disk \*sdkp = scsi\_disk(disk);
struct scsi\_device \*sdev = sdkp->device;
int openers = atomic\_dec\_return(&sdkp->openers);

spin\_lock(&sdkp->openers\_lock);
if (openers == 0 && sdev->removable) {
if (scsi\_block\_when\_processing\_errors(sdev))
scsi\_set\_medium\_removal(sdev, SCSI\_REMOVAL\_ALLOW);
}
spin\_unlock(&sdkp->openers\_lock);

SCSI\_LOG\_HLQUEUE(3, sd\_printk(KERN\_INFO, sdkp, "sd\_release\n"));

scsi\_autopm\_put\_device(sdev);
scsi\_disk\_put(sdkp);
return 0;
}