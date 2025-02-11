if (tun < MIN_TUN_VALUE || tun > MAX_TUN_VALUE) {
 packet\_send\_debug("Invalid tunnel device ID.");
 goto done;
}
sock = tun\_open(tun, mode);

...

done:
if (c == NULL)
 packet\_send\_debug("Failed to open the tunnel device.");
return c;
}