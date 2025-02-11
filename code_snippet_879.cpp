int hns_rcb_set_coalesce_usecs(
struct rcb_common_cb *rcb_common, u32 port_idx, u32 timeout)
{
u32 old_timeout = hns_rcb_get_coalesce_usecs(rcb_common, port_idx);

if (timeout == old_timeout)
return 0;

if (AE\_IS\_VER1(rcb\_common->dsaf\_dev->dsaf\_ver)) {
if (!HNS\_DSAF\_IS\_DEBUG(rcb\_common->dsaf\_dev)) {
dev\_err(rcb\_common->dsaf\_dev->dev,
“error: not support coalesce\_usecs setting!\n”);
return -EINVAL;
}
}

// ADD THIS VALIDATION TO CHECK IF timeout IS WITHIN THE RANGE
if (timeout > HNS\_RCB\_MAX\_COALESCED\_USECS || timeout < 1) {
dev\_err(rcb\_common->dsaf\_dev->dev,
“error: coalesce\_usecs setting supports 1~%d us\n”, HNS\_RCB\_MAX\_COALESCED\_USECS);
return -EINVAL;
}
hns\_rcb\_set\_port\_timeout(rcb\_common, port\_idx, timeout);
return 0;
}