static void dev_seq_printf_stats(struct seq_file *seq, struct net_device *dev)
{
    const struct rtnl_link_stats64 *stats = dev_get_stats(dev);
    char buffer[256]; // fixed-size buffer for storing the device name

    strncpy(buffer, dev->name, sizeof(buffer) - 1); // copy the device name into the buffer
    buffer[sizeof(buffer) - 1] = '\0'; // null-terminate the buffer

    seq_printf(seq, "%6s: %7llu %7llu %4llu %4llu %4llu %5llu %10llu %9llu "
               "%8llu %7llu %4llu %4llu %4llu %5llu %7llu %10llu\n",
               buffer, stats->rx_bytes, stats->rx_packets,
               stats->rx_errors,
               stats->rx_dropped + stats->rx_missed_errors,
               stats->rx_fifo_errors,
               stats->rx_length_errors + stats->rx_over_errors +
               stats->rx_crc_errors + stats->rx_frame_errors,
               stats->rx_compressed, stats->multicast,
               stats->tx_bytes, stats->tx_packets,
               stats->tx_errors, stats->tx_dropped,
               stats->tx_fifo_errors, stats->collisions,
               stats->tx_carrier_errors +
               stats->tx_aborted_errors +
               stats->tx_window_errors +
               stats->tx_heartbeat_errors,
               stats->tx_compressed);
}