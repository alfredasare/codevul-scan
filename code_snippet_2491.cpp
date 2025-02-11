static struct ath_buf *ath_tx_get_buffer(struct ath_softc *sc)
{
	struct ath_buf *bf = NULL;

	spin_lock_bh(&sc->tx.txbuflock);

	if (!list_empty(&sc->tx.txbuf)) {
		bf = list_first_entry(&sc->tx.txbuf, struct ath_buf, list);
		list_del(&bf->list);
		if ( unlikely(bf->flags & ATH_BUF_FREELIST) ) {