struct net_bridge_port {
/* other fields */
atomic\_t refcount;
struct hlist\_node rlist;
};