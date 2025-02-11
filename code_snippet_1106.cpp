static inline void rps_unlock(struct softnet_data *sd)
{
#ifdef CONFIG_RPS
	spin_lock_bh(&sd->input_pkt_queue.lock);
	// Perform necessary operations here
	spin_unlock_bh(&sd->input_pkt_queue.lock);
#endif
}