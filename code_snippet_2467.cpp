htons(sport);
ret = net\_udp\_send(nfs\_con, sizeof(pkt) + datalen \* sizeof(uint32\_t));

return ret;
}

Please note that the check for integer overflow is added before incrementing the `rpc\_id` variable. If an integer overflow is detected, the program will print an error message and exit with a non-zero status code.