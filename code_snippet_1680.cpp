static int llc_ui_autobind(struct socket *sock, struct sockaddr_llc *addr)
{
    //...
    if (!llc->dev) {
        rc = -ENODEV;
        goto out;
    }
    //...
}