#include <linux/mutex.h>

static DEFINE_MUTEX(ksm_thread_sleep_mutex);

static ssize_t sleep_millisecs_show(struct kobject *kobj,
				    struct kobj_attribute *attr, char *buf)
{
	mutex_lock(&ksm_thread_sleep_mutex);
	ssize_t ret = sprintf(buf, "%u\n", ksm_thread_sleep_millisecs);
	mutex_unlock(&ksm_thread_sleep_mutex);
	return ret;
}