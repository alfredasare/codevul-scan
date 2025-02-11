static void llc_sap_rcv(struct llc_sap *sap, struct sk_buff *skb,
                        struct sock *sk)
{
        struct llc_sap_state_ev *ev = llc_sap_ev(skb);

        if (skb->len < sizeof(*ev)) {
                /* Drop the packet if it's too small */
                goto drop;
        }

        ev->type   = LLC_SAP_EV_TYPE_PDU;
        ev->reason = 0;
        skb->sk = sk;
        llc_sap_state_process(sap, skb);

        return;

drop:
        kfree_skb(skb);
}