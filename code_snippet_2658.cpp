grub_disk_dev_t *current, *prev;

/* Find the last element in the list */
current = grub_disk_dev_list;
while (current && current->next) {
    prev = current;
    current = current->next;
}

/* Check if adding the new device would exceed the buffer size */
if (!current || (GRUB_DISK_DEV_LIST_SIZE - 1 <= (size_t)(current - grub_disk_dev_list))) {
    /* Handle the error condition appropriately, e.g., return an error code, log an error message, or abort the operation. */
    return ERROR;
}

/* Add the new device to the list */
dev->next = current->next;
current->next = dev;