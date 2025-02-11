static int snd_seq_ioctl_client_id(struct snd_seq_client *client, void *arg)
{
    int client_id = 0; 
    if (arg && client) { 
        client_id = client->number; 
    } 
    return client_id; 
}