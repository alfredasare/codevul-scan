void nl80211_send_sta_event(struct cfg80211_registered_device *rdev,
			    struct net_device *dev, const u8 *mac_addr,
			    struct station_info *sinfo, gfp_t gfp)
{
	struct sk_buff *msg;
	int required_size = sizeof(struct nlmsghdr) + sizeof(struct genlmsghdr) +
			    NL80211_STA_INFO_MAX_SIZE;

	msg = nlmsg_new(required_size, gfp);
	if (!msg)
		return;

	if (nl80211_send_station(msg, 0, 0, 0, dev, mac_addr, sinfo) < 0) {
		nlmsg_free(msg);
		return;
	}

	genlmsg_multicast_netns(wiphy_net(&rdev->wiphy), msg, 0,
				nl80211_mlme_mcgrp.id, gfp);
}