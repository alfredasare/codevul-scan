static void hci_uart_tty_close(struct tty_struct *tty)
{
    struct hci_uart *temp_hu = tty->disc_data;
    struct hci_dev *hdev;

    BT_DBG("tty %p", tty);

    /* Detach from the tty */
    tty->disc_data = NULL;

    if (!temp_hu)
        return;

    hdev = temp_hu->hdev;
    if (!hdev)
        return;

    if (test_bit(HCI_UART_PROTO_READY, &temp_hu->flags)) {
        percpu_down_write(&temp_hu->proto_lock);
        clear_bit(HCI_UART_PROTO_READY, &temp_hu->flags);
        percpu_up_write(&temp_hu->proto_lock);

        cancel_work_sync(&temp_hu->write_work);

        if (hdev) {
            if (test_bit(HCI_UART_REGISTERED, &temp_hu->flags))
                hci_unregister_dev(hdev);
            hci_free_dev(hdev);
        }
        temp_hu->proto->close(temp_hu);
    }

    clear_bit(HCI_UART_PROTO_SET, &temp_hu->flags);

    percpu_free_rwsem(&temp_hu->proto_lock);

    kfree(temp_hu);
}