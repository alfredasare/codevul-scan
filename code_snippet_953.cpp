entry_guard_chan_failed(channel_t *chan)
{
  if (!chan)
    return;

  smartlist_t *pending = smartlist_new();
  circuit_get_all_pending_on_channel(pending, chan);
  SMARTLIST_FOREACH(pending, circuit_t *, circ) {
    if (!CIRCUIT_IS_ORIGIN(circ))
      continue;

    origin_circuit_t *origin_circ = TO_ORIGIN_CIRCUIT(circ);
    if (origin_circ->guard_state) {
      /* We might have no guard state if we didn't use a guard on this
       * circuit (eg it's for a fallback directory). */
      entry_guard_failed(&origin_circ->guard_state);
    }
  }
  smartlist_free(pending);
}