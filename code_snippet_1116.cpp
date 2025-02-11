c++
UsbTransferFunction::~UsbTransferFunction() {
    // Close and release the USB transfer endpoint
    if (m_transferEndpoint) {
        usb_close(m_transferEndpoint);
        m_transferEndpoint = nullptr;
    }

    // Free the USB transfer buffer
    if (m_transferBuffer) {
        free(m_transferBuffer);
        m_transferBuffer = nullptr;
    }
}