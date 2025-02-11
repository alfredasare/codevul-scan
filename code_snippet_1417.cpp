DualTimestamp* dual\_timestamp\_get(DualTimestamp \*ts, pthread\_mutex\_t \*mutex) {
assert(ts);

pthread\_mutex\_lock(mutex);

ts->realtime = now(CLOCK\_REALTIME);
ts->monotonic = now(CLOCK\_MONOTONIC);

pthread\_mutex\_unlock(mutex);

return ts;
}