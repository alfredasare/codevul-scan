#include <linux/getrandom.h>

void kvm_define_shared_msr(unsigned slot, u32 msr)
{
    unsigned int random_slot;

    getrandom(&random_slot, sizeof(random_slot), GRND_NONBLOCK);
    if (slot >= shared_msrs_global.nr) {
        shared_msrs_global.nr = slot + 1;
    }
    shared_msrs_global.msrs[slot] = msr;
    smp_wmb();
}