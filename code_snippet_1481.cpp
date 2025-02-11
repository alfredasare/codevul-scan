faddr = daddr;
minfo.lport = inc->i\_hdr.h\_sport;
minfo.fport = inc->i\_hdr.h\_dport;
}

minfo.flags = 0;

rds\_info\_copy(iter, &minfo, minfo.len);
}

Please note that the change in the last line of the function is also necessary to prevent the buffer overflow when calling rds\_info\_copy(). The original function calls rds\_info\_copy() with the size of the minfo structure, but now it should call it with minfo.len, which is the validated length of the data being copied.