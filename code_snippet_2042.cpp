size_t sent_ulong = (unsigned) sent;
total += sent_ulong;
if (sent_ulong >= remaining)
    remaining = 0;
else
    remaining -= sent_ulong;