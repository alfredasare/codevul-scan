static int nl80211_testmode_do(struct sk_buff *skb, struct genl_info *info)
{
    struct cfg80211_registered_device *rdev = info->user_ptr[0];
    int err;
    size_t len;

    if (!info->attrs[NL80211_ATTR_TESTDATA])
        return -EINVAL;

    len = nla_len(info->attrs[NL80211_ATTR_TESTDATA]);
    if (len > MAX_TESTDATA_SIZE) {
        err = -E2BIG;
        goto out;
    }

    err = -EOPNOTSUPP;
    if (rdev->ops->testmode_cmd) {
        rdev->testmode_info = info;
        err = rdev->ops->testmode_cmd(&rdev->wiphy,
                nla_data(info->attrs[NL80211_ATTR_TESTDATA]), len);
        rdev->testmode_info = NULL;
    }

out:
    return err;
}