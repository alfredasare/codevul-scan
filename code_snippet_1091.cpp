write_ruleset_details(int s)
{
    //... (rest of the function remains the same)

    while(get_redirect_rule_by_index(i, 0/*ifname*/, &eport, iaddr, sizeof(iaddr),
                                     &iport, &proto, desc, sizeof(desc),
                                     rhost, sizeof(rhost),
                                     &timestamp,
                                     &packets, &bytes) >= 0)
    {
        // Validate and sanitize input data
        if (proto < 0 || proto > 255) {
            error("Invalid protocol value");
            continue;
        }
        if (eport < 0 || eport > 65535) {
            error("Invalid eport value");
            continue;
        }
        if (iport < 0 || iport > 65535) {
            error("Invalid iport value");
            continue;
        }

        // Add security header
        char buffer[256];
        int n = snprintf(buffer, sizeof(buffer),
                          " Ruleset :\n"
                          "---------------------\n"
                          "Proto: %d\n"
                          "Eport: %hu\n"
                          "Iport: %hu\n"
                          "Desc: %s\n"
                          "Rhost: %s\n"
                          "Timestamp: %u\n"
                          "Packets: %" PRIu64 "\n"
                          "Bytes: %" PRIu64 "\n\n",
                          proto, (unsigned short)eport, (unsigned short)iport, desc, rhost, timestamp, packets, bytes);

        write(s, buffer, n);
        i++;
    }
}