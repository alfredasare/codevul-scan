const nsecs_t kMaxWaitTime = 5000000000LL; // 5 seconds in nanoseconds
nsecs_t totalWaitTime = 0;

while (true) {
    binder = sm->getService(String1