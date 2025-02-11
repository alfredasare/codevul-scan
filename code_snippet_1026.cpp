static int lxc_attach\_drop\_privs(struct lxc\_proc\_context\_info \*ctx) {
 int last\_cap = lxc\_caps\_last\_cap();
 pid\_t child\_pid;

child\_pid = fork();
if (child\_pid == 0) { /* Child process */
int dropped\_cap;

dropped\_cap = lxc\_attach\_drop\_privs\_check(ctx, last\_cap);
if (dropped\_cap > 0) {
prctl(PR\_CAPBSET\_DROP, dropped\_cap, 0, 0, 0);
}
exit(0);
} else if (child\_pid > 0) { /* Parent process */
wait(NULL);
} else { /* Error in fork */
SYSERROR("failed to fork");
return -1;
}

return 0;
}

static int lxc\_attach\_drop\_privs\_check(struct lxc\_proc\_context\_info \*ctx, int last\_cap) {
int cap;

for (cap = 0; cap <= last\_cap; cap++) {
if (ctx->capability\_mask & (1LL << cap))
continue;

return cap;
}

return -1;
}