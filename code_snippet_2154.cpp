static int virtio_net_handle_offloads(VirtIONet *n, uint8_t cmd,
                                     struct iovec *iov, unsigned int iov_cnt)
{
    VirtIODevice *vdev = VIRTIO_DEVICE(n);
    uint64_t offloads;
    size_t s;
    ssize_t iov_total_length = iov_length(iov, iov_cnt);

    if (!will_iov_fit_in_buf(iov_total_length, sizeof(offloads))) {
        return VIRTIO_NET_ERR;
    }

    s = iov_to_buf(iov, iov_cnt, 0, &offloads, sizeof(offloads));
    if (s != sizeof(offloads)) {
        return VIRTIO_NET_ERR;
    }

    if (cmd == VIRTIO_NET_CTRL_GUEST_OFFLOADS_SET) {
        uint64_t supported_offloads;

        if (!n->has_vnet_hdr) {
            return VIRTIO_NET_ERR;
        }

        supported_offloads = virtio_net_supported_guest_offloads(n);
        if (offloads & ~supported_offloads) {
            return VIRTIO_NET_ERR;
        }

        n->curr_guest_offloads = offloads;
        virtio_net_apply_guest_offloads(n);

        return VIRTIO_NET_OK;
    } else {
        return VIRTIO_NET_ERR;
    }
}

static ssize_t iov_length(struct iovec *iov, unsigned int iov_cnt)
{
    ssize_t total_length = 0;
    unsigned int i;

    for (i = 0; i < iov_cnt; i++) {
        total_length += iov[i].iov_len;
    }

    return total_length;
}

static bool will_iov_fit_in_buf(ssize_t iov_len, size_t buf_size)
{
    return iov_len <= buf_size;
}