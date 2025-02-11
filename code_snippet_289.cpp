static void pppol2tp_copy_stats(struct pppol2tp_ioc_stats *dest,
				struct l2tp_stats *stats)
{
	dest->tx_packets = atomic_long_read_relaxed(&stats->tx_packets);
	dest->tx_bytes = atomic_long_read_relaxed(&stats->tx_bytes);
	dest->tx_errors = atomic_long_read_relaxed(&stats->tx_errors);
	dest->rx_packets = atomic_long_read_relaxed(&stats->rx_packets);
	dest->rx_bytes = atomic_long_read_relaxed(&stats->rx_bytes);
	dest->rx_seq_discards = atomic_long_read_relaxed(&stats->rx_seq_discards);
	dest->rx_oos_packets = atomic_long_read_relaxed(&stats->rx_oos_packets);
	dest->rx_errors = atomic_long_read_relaxed(&stats->rx_errors);
}