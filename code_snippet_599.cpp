static void hns_nic_rx_up_pro(struct hns_nic_ring_data *ring_data, struct sk_buff *skb)
{
	struct net_device *ndev = ring_data->napi.dev;
	u16 protocol;

	protocol = eth_type_trans(skb, ndev);
	skb_set_protocol(skb, protocol);
	napi_gro_receive(&ring_data->napi, skb);
}