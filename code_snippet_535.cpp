static void efx_ethtool_get_pauseparam(struct net_device *net_dev,
				       struct ethtool_pauseparam *pause)
{
	struct efx_nic *efx = netdev_priv(net_dev);
	unsigned int wanted_fc = efx->wanted_fc; // Ensure correct data type

	pause->rx_pause =!!(wanted_fc & (EFX_FC_RX | 0xFF));
	pause->tx_pause =!!(wanted_fc & (EFX_FC_TX | 0xFF));
	pause->autoneg =!!(wanted_fc & (EFX_FC_AUTO | 0xFF));

}