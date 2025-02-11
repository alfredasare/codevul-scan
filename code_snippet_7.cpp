static void nci\_core\_generic\_error\_ntf\_packet(struct nci\_dev \*ndev,
struct sk\_buff \*skb)
{
if (skb->len < 1) {
pr\_err("Invalid data length\n");
return;
}

\_\_u8 status = skb->data[0];

pr\_debug("status 0x%x\n", status);

if (atomic\_read(&ndev->state) == NCI\_W4\_HOST\_SELECT) {
/* Activation failed, so complete the request
(the state remains the same) */
nci\_req\_complete(ndev, status);
}
}