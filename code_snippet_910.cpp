if (i > DCB_CAP_ATTR_MAX || i < DCB_CAP_ATTR_ALL+1)
                continue;

        if (!netdev->dcbnl_ops->getcap(netdev, i, &value)) {
                ret = nla_put_u8(skb, i, value);
                if (ret) {
                        nla_nest_cancel(skb, nest);
                        return ret;
                }
        }
}
nla_nest_end(skb, nest);

return 0;