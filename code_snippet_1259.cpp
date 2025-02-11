static void _devm_mdiobus_free(struct device *dev, void *res)
{
	struct device *mii_bus_dev = *(struct device **)res;

	if (mii_bus_dev && mii_bus_dev->bus == &mdiobus_type) {
		mdiobus_free(container_of(mii_bus_dev, struct mii_bus, dev));
	} else {
		dev_err(dev, "%s: Invalid MII bus pointer\n", __func__);
	}
}