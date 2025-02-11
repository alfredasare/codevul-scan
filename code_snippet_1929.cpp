static void check\_guest\_throttling(void)
{
if (!mig\_throttle\_on) {
return;
}

int64\_t t1 = qemu\_clock\_get\_ns(QEMU\_CLOCK\_REALTIME);

if (!atomic\_load(&t0)) {
atomic\_init(&t0, t1);
return;
}

if (40 < (t1-atomic\_load(&t0))/1000000) {
mig\_throttle\_guest\_down();
atomic\_compare\_exchange\_weak(&t0, &t0, &t1);
}
}