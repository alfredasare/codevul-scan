grub_disk_dev_register (grub_disk_dev_t dev)
{
  if (!dev ||!dev->name ||!dev->disk) {
    return GRUB_ERROR_INVALID_PARAMETER;
  }

  dev->next = grub_disk_dev_list;
  grub_disk_dev_list = dev;

  return GRUB_SUCCESS;
}