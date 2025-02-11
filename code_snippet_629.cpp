static void megasas_frame_set_scsi_status(MegasasState *s,
                                         unsigned long frame, uint8_t v)
{
    PCIDevice *pci = &s->parent_obj;
    uint8_t scsi_status = v; // Assuming v is a valid value
    
    if (stb_pci_dma(pci, frame + offsetof(struct mfi_frame_header, scsi_status), scsi_status) < 0) {
        log_error("Failed to set SCSI status: %d", errno);
    }
}