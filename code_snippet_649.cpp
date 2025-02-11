static void efx_ethtool_get_pauseparam(struct net_device *net_dev,
                                       struct ethtool_pauseparam *pause)
{
        struct efx_nic *efx = netdev_priv(net_dev);
        struct efx_fc fc;
        bool link_up;

        link_up = efx_ethtool_op_get_link(net_dev, true);
        if (!link_up) {
                /* Return 0 for all fields if the link is down */
                pause->rx_pause = 0;
                pause->tx_pause = 0;
                pause->autoneg = 0;
                return;
        }

        mutex_lock(&efx->wanted_fc_mutex);
        fc = efx->wanted_fc;
        mutex_unlock(&efx->wanted_fc_mutex);

        pause->rx_pause = !!(fc & EFX_FC_RX);
        pause->tx_pause = !!(fc & EFX_FC_TX);
        pause->autoneg = !!(fc & EFX_FC_AUTO);
}