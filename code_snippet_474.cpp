static void vfio_msi_disable(struct vfio_pci_device *vdev, bool msix)
{
    struct pci_dev *pdev = vdev->pdev;
    size_t i;

    for (i = 0; i < (size_t)vdev->num_ctx; i++) { // Use size_t type for loop counter
        vfio_virqfd_disable(&vdev->ctx[i].unmask);
        vfio_virqfd_disable(&vdev->ctx[i].mask);
    }

    vfio_msi_set_block(vdev, 0, (size_t)vdev->num_ctx, NULL, msix);

    pci_free_irq_vectors(pdev);

    if (vdev->nointx)
        pci_intx(pdev, 0);

    vdev->irq_type = VFIO_PCI_NUM_IRQS;
    vdev->num_ctx = 0; // Ensure num_ctx is set to 0 before freeing ctx
    kfree(vdev->ctx);
}