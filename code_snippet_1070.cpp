static void _devm_mdiobus_free(struct device *dev, void *res)
{
    struct mii_bus *bus = *(struct mii_bus **)res;
    if (bus && bus!= NULL) {
        mdiobus_free(bus);
    }
}