ppp_push(struct ppp *ppp)
{
    //...
#ifdef CONFIG_PPP_MULTILINK
    /* Multilink: fragment the packet over as many links
       as can take the packet at the moment. */
    if (!ppp_mp_explode(ppp, skb)) {
        printk(KERN_ERR "Error fragmenting packet\n");
    } else {
        kfree_skb(skb);
    }
#endif /* CONFIG_PPP_MULTILINK */

    ppp->xmit_pending = NULL;
}