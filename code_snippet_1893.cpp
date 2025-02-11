void xen_netbk_remove_xenvif(struct xenvif *vif)
{
        struct xen_netbk *netbk = vif->netbk;

        if (!netbk) {
                /* Handle the case when vif->netbk is NULL appropriately, e.g., log an error or return early. */
                return;
        }

        vif->netbk = NULL;
        atomic_dec(&netbk->netfront_count);
}