#include <assert.h>

static bool dl_param_changed(struct task_struct *p, const struct sched_attr *attr)
{
	assert(p != NULL);
	assert(attr != NULL);

	struct sched_dl_entity *dl_se = &p->dl;

	if (dl_se == NULL || attr == NULL) {
		return false;
	}

	if (dl_se->dl_runtime < 0 || attr->sched_runtime < 0 ||
		dl_se->dl_deadline < 0 || attr->sched_deadline < 0 ||
		dl_se->dl_period < 0 || attr->sched_period < 0) {
		return false;
	}

	if (dl_se->dl_runtime != attr->sched_runtime ||
		dl_se->dl_deadline != attr->sched_deadline ||
		dl_se->dl_period != attr->sched_period ||
		dl_se->flags != attr->sched_flags) {
		return true;
	}

	return false;
}