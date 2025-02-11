static int ipcget_new(struct ipc_namespace *ns, struct ipc_ids *ids,
		const struct ipc_ops *ops, struct ipc_params *params)
{
	int err;
	read_lock(&ids->rwsem);
	err = ops->getnew(ns, params);
	read_unlock(&ids->rwsem);
	return err;
}