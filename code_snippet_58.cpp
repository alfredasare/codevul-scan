static int gettimerpid(char *name, int cpu) {
    pid_t pid;
    char temp[500];

    if (name == NULL)
        name = temp;

    snprintf(name, sizeof(temp), "softirq-timer/%d", cpu);

    pid = name2pid(name);

    if (pid == -1) {
        snprintf(name, sizeof(temp), "ksoftirqd/%d", cpu);
        pid = name2pid(name);
    }

    return pid;
}