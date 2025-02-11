void channel_unlink_all_circuits(channel_t *chan)
{
  if (!chan ||!chan->cmux) {
    log_warn("Invalid channel or cmux pointer");
    return; 
  }
  
  circuitmux_detach_all_circuits(chan->cmux);
  chan->num_n_circuits = 0;
  chan->num_p_circuits = 0;
}