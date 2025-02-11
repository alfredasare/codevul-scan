void mlx4_init_vlan_table(struct mlx4_dev *dev, struct mlx4_vlan_table *table)
{
    int i;

    mutex_init(&table->mutex);
    for (i = 0; i < MLX4_MAX_VLAN_NUM; i++) {
        table->entries[i] = 0;
        table->refs[i]    = 0;
    }
    table->max   = MIN(MLX4_MAX_VLAN_NUM, 1 << dev->caps.log_num_vlans);
    table->total = 0;

    if (dev->caps.log_num_vlans > sizeof(int) * 8) {
        dev_err(dev, "log_num_vlans value too large\n");
        return;
    }
}