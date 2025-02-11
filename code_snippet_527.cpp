partition\_table\_create\_device\_not\_changed\_cb(gpointer user\_data)
{
g\_signal\_handler\_block(data->device->priv->daemon, data->device\_changed\_signal\_handler\_id);

CreatePartitionTableData \*data = user\_data;

if (partition\_table\_device\_is\_changed(data->device))
{
g\_signal\_handler\_unblock(data->device->priv->daemon, data->device\_changed\_signal\_handler\_id);
throw\_error(data->context, ERROR\_FAILED, "Error creating partition table: device changed during operation");
return FALSE;
}

// Rest of the function remains unchanged
g\_signal\_handler\_disconnect(data->device->priv->daemon, data->device\_changed\_signal\_handler\_id);
partition\_table\_create\_data\_unref(data);

return FALSE;
}