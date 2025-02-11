static void dev_seq_printf_stats(struct seq_file *seq, struct net_device *dev)
{
	const struct rtnl_link_stats64 *stats = dev_get_stats(dev);

	seq_printf(seq, "%s: %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu\n",
		   dev->name, stats->rx_bytes, stats->rx_packets,
		   stats->rx_errors,
		   stats->rx_dropped, stats->rx_fifo_errors,
		   stats->rx_length_errors, stats->rx_over_errors,
		   stats->rx_crc_errors, stats->rx_frame_errors,
		   stats->rx_compressed, stats->multicast,
		   stats->tx_bytes, stats->tx_packets,
		   stats->tx_errors, stats->tx_dropped,
		   stats->tx_fifo_errors,
		   stats->tx_carrier_errors + stats->tx_aborted_errors +
		    stats->tx_window_errors + stats->tx_heartbeat_errors,
		   stats->tx_compressed);
}