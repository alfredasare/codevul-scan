static void hci\_uart\_tty\_close(struct tty\_struct *tty)
{
 struct hci\_uart *hu = tty->disc\_data;
 struct hci\_dev *hdev;

BT\_DBG("tty %p", tty);

/* Detach from the tty */
tty->disc\_data = NULL;

if (!hu)
return;

hdev = hu->hdev;
if (hdev) {
hci\_uart\_close(hdev);
return;
}

if (test\_bit(HCI\_UART\_PROTO\_READY, &hu->flags)) {
percpu\_down\_write(&hu->proto\_lock);
clear\_bit(HCI\_UART\_PROTO\_READY, &hu->flags);
percpu\_up\_write(&hu->proto\_lock);

cancel\_work\_sync(&hu->write\_work);

if (test\_bit(HCI\_UART\_REGISTERED, &hu->flags))
hci\_unregister\_dev(hdev);
hci\_free\_dev(hdev);
}
hu->proto->close(hu);

clear\_bit(HCI\_UART\_PROTO\_SET, &hu->flags);

percpu\_free\_rwsem(&hu->proto\_lock);

kfree(hu);
}