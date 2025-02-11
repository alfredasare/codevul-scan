static int vmw_legacy_srf_destroy(struct vmw_resource *res)
{
    struct vmw_private *dev_priv = res->dev_priv;
    uint32_t submit_size;
    uint8_t *cmd;

    BUG_ON(res->id == -1);

    /*... */

    if (unlikely(!cmd)) {
        DRM_ERROR("Failed to reserve FIFO space\n");
        return -ENOMEM;
    }

    /*... */
}