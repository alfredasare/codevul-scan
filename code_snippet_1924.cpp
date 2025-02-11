static unsigned long klsi_105_status2linestate(const __u16 status)
{
    unsigned long res = 0;
    const unsigned int MAX_STATUS_SIZE = 2; // Define a maximum size for the status variable

    if (status > (1 << (sizeof(__u16) * 8 - 1))) { // Check if the status value is within the expected range
        return 0; // or handle the error as per your requirements
    }

    res =   ((status & KL5KUSB105A_DSR)? TIOCM_DSR : 0)
           | ((status & KL5KUSB105A_CTS)? TIOCM_CTS : 0)
           ;

    return res;
}