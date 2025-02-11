void xen\_pcibk\_config\_free\_dev(struct pci\_dev *dev)
{
struct xen\_pcibk\_dev\_data *dev\_data = pci\_get\_drvdata(dev);
struct config\_field\_entry *cfg\_entry, *t;
const struct config\_field \*field;

dev\_dbg(&dev->dev, "free-ing virtual configuration space fields\n");
if (!dev\_data)
return;

spin\_lock(&dev\_data->config\_fields\_lock);
list\_for\_each\_entry\_safe(cfg\_entry, t, &dev\_data->config\_fields, list) {
list\_del(&cfg\_entry->list);

field = cfg\_entry->field;

if (field->release)
field->release(dev, OFFSET(cfg\_entry), cfg\_entry->data);

kfree(cfg\_entry);
}
spin\_unlock(&dev\_data->config\_fields\_lock);
}