static int atl2_get_eeprom_len(struct net_device *netdev)
{
    struct atl2_adapter *adapter = netdev_priv(netdev);

    if (!atl2_check_eeprom_exist(&adapter->hw)) {
        dev_err(&adapter->pdev->dev, "EEPROM does not exist\n");
        return -ENODEV;
    }
    return 0;
}