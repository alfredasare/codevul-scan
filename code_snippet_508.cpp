c++
static void __netdev_adjacent_dev_unlink_neighbour(struct net_device *dev,
						   struct net_device *upper_dev)
{
	if (dev && upper_dev) {
		__netdev_adjacent_dev_unlink(dev, upper_dev);
		__netdev_adjacent_dev_unlink_lists(dev, upper_dev,
						   &dev->adj_list.upper,
						   &upper_dev->adj_list.lower);
	}
}