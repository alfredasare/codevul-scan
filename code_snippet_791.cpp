static void safe_free_urb(struct urb *urb)
{
	unsigned long offset = buffer_offset(urb->transfer_buffer);
	void *transfer_buffer_checked;

	if (!urb || !urb->transfer_buffer)
		return;

	transfer_buffer_checked = urb->transfer_buffer - offset;

	if (urb->transfer_flags & URB_NO_TRANSFER_DMA_MAP) {
		usb_free_coherent(
			urb->dev,
			urb->transfer_buffer_length + offset,
			transfer_buffer_checked,
			urb->transfer_dma - offset);
	} else {
		kfree(transfer_buffer_checked);
	}

	usb_free_urb(urb);
}