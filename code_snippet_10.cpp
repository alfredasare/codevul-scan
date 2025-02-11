timespec_to_jiffies(const struct timespec *value)
{
    uint64_t sec = (uint64_t)value->tv_sec;
    uint64_t nsec = (uint64_t)value->tv_nsec + TICK_NSEC - 1;

    if (sec >= MAX_SEC_IN_JIFFIES){
        sec = MAX_SEC_IN_JIFFIES;
        nsec = 0;
    }
    return (((uint64_t)sec * SEC_CONVERSION) +
            (((uint64_t)nsec * NSEC_CONVERSION) >>
             (NSEC_JIFFIE_SC - SEC_JIFFIE_SC))) >> SEC_JIFFIE_SC;
}