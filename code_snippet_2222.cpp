int iwl_sta_tx_modify_enable_tid(struct iwl_priv *priv, int sta_id, int tid)
{
    unsigned long flags;
    struct iwl_addsta_cmd sta_cmd;
    enum { MAX_TID = 15 };

    lockdep_assert_held(&priv->shrd->mutex);

    /* Validate the tid parameter */
    if (tid < 0 || tid >= MAX_TID) {
        return -EINVAL;
    }

    spin_lock_irqsave(&priv->shrd->sta_lock, flags);
    priv->stations[sta_id].sta.tid_disable_tx &= ~(1 << tid);
    spin_unlock_irqrestore(&priv->shrd->sta_lock, flags);

    return iwl_send_add_sta(priv, &sta_cmd, CMD_SYNC);
}