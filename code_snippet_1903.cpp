size_t nlmsg_parse(struct nlmsghdr *nlh, size_t hdrlen, struct nlattr *tb[],
                   size_t maxtype, struct nla_policy *policy)
{
    if (!nlmsg_valid_hdr(nlh, hdrlen)) {
        return -NLE_MSG_TOOSHORT;
    }

    if (hdrlen > sizeof(struct nlmsghdr)) {
        return -NLE_MSG_TOO_LARGE;
    }

    return nla_parse(tb, (int)maxtype, nlmsg_attrdata(nlh, hdrlen),
                     nlmsg_attrlen(nlh, hdrlen), policy);
}