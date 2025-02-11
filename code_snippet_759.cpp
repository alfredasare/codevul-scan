static void Ins_LT(INS_ARG) {
    (void)exc;
    if (args[0] >= 0 && args[0] < ARRAY_SIZE && args[1] >= 0 && args[1] < ARRAY_SIZE) {
        if (args[0] < args[1])
            args[0] = 1;
        else
            args[0] = 0;
    } else {
        // Handle invalid input or out-of-bounds indices
    }
}