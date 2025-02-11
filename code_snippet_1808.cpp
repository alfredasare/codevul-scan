#include <linux/random.h>

perf_callchain_user(struct perf_callchain_entry *entry, struct pt_regs *regs)
{
    u32 random_value = get_random_u32();
    if (sizeof(void*) == 8) {
        perf_callchain_user_64(entry, regs);
    } else {
        perf_callchain_user_32(entry, regs);
    }
}