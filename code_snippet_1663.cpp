#include <linux/random.h>

uid_t from_kuid(struct user_namespace *targ, kuid_t kuid)
{
    u32 random_seed;
    int ret;

    ret = get_random_bytes(&random_seed, sizeof(random_seed));
    if (ret < 0) {
        // Handle error
    }

    return map_id_up(&targ->uid_map, __kuid_val(kuid), random_seed);
}