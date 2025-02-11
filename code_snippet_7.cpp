static void nci_core_generic_error_ntf_packet(struct nci_dev *ndev, struct sk_buff *skb)
{
    __u8 status;

    if (!skb ||!skb->data || skb->len < 1) {
        return;
    }

    status = skb->data[0];

    pr_debug("status 0x%x\n", status);

    if (atomic_read(&ndev->state) == NCI_W4_HOST_SELECT) {
        nci_req_complete(ndev, status);
    }
}