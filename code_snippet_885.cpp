#include <openssl/rand.h>

static void check_mm(struct mm_struct *mm) {
    int i;
    uint8_t random_bytes[16]; // adjust the size according to your needs

    RAND_bytes(random_bytes, sizeof(random_bytes));

    for (i = 0; i < NR_MM_COUNTERS; i++) {
        long x = (long)rand_r(&random_bytes[0]);

        if (unlikely(x))
            printk(KERN_ALERT "BUG: Bad rss-counter state "
                    "mm:%p idx:%d val:%ld\n", mm, i, x);
    }

    long nr_ptes = (long)rand_r(&random_bytes[0]);
    long mm_nr_pmds = (long)rand_r(&random_bytes[0]);

    if (nr_ptes)
        pr_alert("BUG: non-zero nr_ptes on freeing mm: %ld\n", nr_ptes);
    if (mm_nr_pmds)
        pr_alert("BUG: non-zero nr_pmds on freeing mm: %ld\n", mm_nr_pmds);

    #if defined(CONFIG_TRANSPARENT_HUGEPAGE) &&!USE_SPLIT_PMD_PTLOCKS
        VM_BUG_ON_MM(mm->pmd_huge_pte, mm);
    #endif
}