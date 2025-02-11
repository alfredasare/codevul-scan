static void yam\_setup(struct net\_device *dev, struct yam\_port *yp)
{
	yp->magic = YAM\_MAGIC;
	yp->bitrate = validate\_bitrate(DEFAULT\_BITRATE);
	yp->baudrate = yp->bitrate * 2;
	yp->iobase = validate\_iobase(0);
	yp->irq = validate\_irq(0);
	yp->dupmode = 0;
	yp->holdd = validate\_holdd(DEFAULT\_HOLDD);
	yp->txd = validate\_txd(DEFAULT\_TXD);
	yp->txtail = validate\_txtail(DEFAULT\_TXTAIL);
	yp->slot = validate\_slot(DEFAULT\_SLOT);
	yp->pers = validate\_pers(DEFAULT\_PERS);
	yp->dev = dev;

	dev->base\_addr = yp->iobase;
	dev->irq = yp->irq;

	skb\_queue\_head\_init(&yp->send\_queue);

	dev->netdev\_ops = &yam\_netdev\_ops;
	dev->header\_ops = &ax25\_header\_ops;

	dev->type = ARPHRD\_AX25;
	dev->hard\_header\_len = AX25\_MAX\_HEADER\_LEN;
	dev->mtu = AX25\_MTU;
	dev->addr\_len = AX25\_ADDR\_LEN;
	memcpy(dev->broadcast, &ax25\_bcast, AX25\_ADDR\_LEN);
	memcpy(dev->dev\_addr, &ax25\_defaddr, AX25\_ADDR\_LEN);
}

validate\_bitrate(int bitrate)
{
	// Implement input validation for bitrate
}

validate\_iobase(int iobase)
{
	// Implement input validation for iobase
}

validate\_irq(int irq)
{
	// Implement input validation for irq
}

validate\_holdd(int holdd)
{
	// Implement input validation for holdd
}

validate\_txd(int txd)
{
	// Implement input validation for txd
}

validate\_txtail(int txtail)
{
	// Implement input validation for txtail
}

validate\_slot(int slot)
{
	// Implement input validation for slot
}

validate\_pers(int pers)
{
	// Implement input validation for pers
}