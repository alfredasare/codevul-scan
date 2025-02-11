void nl80211_send_sta_event(struct cfg80211_registered_device *rdev,
			    struct net_device *dev, const u8 *mac_addr,
			    struct station_info *sinfo, gfp_t gfp)
{
    struct sk_buff *msg;

    // Validate and sanitize the mac_addr parameter
    char sanitized_mac_addr[18];
    if (!is_valid_mac_address(mac_addr)) {
        return;
    }
    sanitize_mac_address(mac_addr, sanitized_mac_addr);

    msg = nlmsg_new(NLMSG_GOODSIZE, gfp);
    if (!msg)
        return;

    if (nl80211_send_station(msg, 0, 0, 0, dev, sanitized_mac_addr, sinfo) < 0) {
        nlmsg_free(msg);
        return;
    }

    genlmsg_multicast_netns(wiphy_net(&rdev->wiphy), msg, 0,
                            nl80211_mlme_mcgrp.id, gfp);
}

bool is_valid_mac_address(const u8 *mac_addr) {
    int i;
    for (i = 0; i < 6; i++) {
        if (!isxdigit((unsigned char)mac_addr[i])) {
            return false;
        }
    }
    return true;
}

void sanitize_mac_address(const u8 *mac_addr, char *sanitized_mac_addr) {
    int i;
    for (i = 0; i < 17; i++) {
        sanitized_mac_addr[i] = (char)(mac_addr[i] >= 'a' && mac_addr[i] <= 'f')? (char)(mac_addr[i] - 'a' + 'A') : (char)(mac_addr[i]);
    }
    sanitized_mac_addr[17] = '\0';
}