int iwl_sta_tx_modify_enable_tid(struct iwl_priv *priv, int sta_id, int tid)
{
	unsigned long flags;
	struct iwl_addsta_cmd sta_cmd;
	struct iwl_sta *sta = &priv->stations[sta_id].sta;

	lockdep_assert_held(&priv->shrd->mutex);

	mutex_lock(&sta->tid_disable_tx_mutex);

	/* Remove "disable" flag, to enable Tx for this TID */
	sta->modify_mask = STA_MODIFY_TID_DISABLE_TX;
	sta->tid_disable_tx &= cpu_to_le16(~(1 << tid));
	sta->mode = STA_CONTROL_MODIFY_MSK;
	memcpy(&sta_cmd, sta, sizeof(struct iwl_addsta_cmd));

	mutex_unlock(&sta->tid_disable_tx_mutex);

	return iwl_send_add_sta(priv, &sta_cmd, CMD_SYNC);
}