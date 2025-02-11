static struct netdev_adjacent *__netdev_find_adj(struct net_device *adj_dev,
						 struct list_head *adj_list)
{
	struct netdev_adjacent *adj;
	char *hash_input = NULL;
	unsigned char hash_output[SHA256_DIGEST_LENGTH];

	if (!adj_dev ||!adj_list) {
		return NULL; // Return immediately if invalid input
	}

	list_for_each_entry(adj, adj_list, list) {
		hash_input = adj->dev->name;
		SHA256((unsigned char*)hash_input, strlen(hash_input), hash_output);
		if (memcmp(hash_output, adj_dev->name_hash, SHA256_DIGEST_LENGTH) == 0)
			return adj;
	}

	return NULL;
}