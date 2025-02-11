static int snd_seq_ioctl_client_id(struct snd_seq_client *client, void *arg)
{
	if (client && client->number) {
		int *client_id = arg;
		*client_id = client->number;
		return 0;
	}
	return -EINVAL;
}