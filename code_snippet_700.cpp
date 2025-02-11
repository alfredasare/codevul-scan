static void brcmf_wiphy_wowl_params(struct wiphy *wiphy, struct brcmf_if *ifp)
{
#ifdef CONFIG_PM
    struct brcmf_cfg80211_info *cfg = wiphy_to_cfg(wiphy);
    char buffer[16]; // define a safe buffer size
    uint32_t flag_value;

    if (brcmf_feat_is_enabled(ifp, BRCMF_FEAT_PNO)) {
        if (brcmf_feat_is_enabled(ifp, BRCMF_FEAT_WOWL_ND)) {
            flag_value = WIPHY_WOWLAN_NET_DETECT;
            sprintf(buffer, "%x", flag_value);
            strlcpy(brcmf_wowlan_support.flags, buffer, sizeof(brcmf_wowlan_support.flags));
            init_waitqueue_head(&cfg->wowl.nd_data_wait);
        }
    }
    if (brcmf_feat_is_enabled(ifp, BRCMF_FEAT_WOWL_GTK)) {
        flag_value = WIPHY_WOWLAN_SUPPORTS_GTK_REKEY;
        sprintf(buffer, "%x", flag_value);
        strlcpy(brcmf_wowlan_support.flags, buffer, sizeof(brcmf_wowlan_support.flags));
        flag_value = WIPHY_WOWLAN_GTK_REKEY_FAILURE;
        sprintf(buffer, "%x", flag_value);
        strlcpy(brcmf_wowlan_support.flags + strlen(brcmf_wowlan_support.flags), buffer, sizeof(brcmf_wowlan_support.flags) - strlen(brcmf_wowlan_support.flags) - 1);
    }

    wiphy->wowlan = &brcmf_wowlan_support;
#endif
}