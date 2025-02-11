int nlmsg_parse(struct nlmsghdr *nlh, int hdrlen, struct nlattr *tb[],
                int maxtype, struct nla_policy *policy)
{
        if (!nlmsg_valid_hdr(nlh, hdrlen))
                return -NLE_MSG_TOOSHORT;

        for (int i = 0; i < nla_len(nlh, hdrlen); i++) {
                struct nlattr *attr = nla_find(tb, i);
                if (!attr)
                        continue;

                if (attr->nla_type > maxtype) {
                        pr_warn("nlmsg_parse: Invalid attribute type %d, max type is %d\n",
                                attr->nla_type, maxtype);
                        return -EINVAL;
                }

                if (nla_parse(tb, maxtype, nla_data(attr), nla_len(attr), policy) < 0)
                        return -EINVAL;
        }

        return 0;
}