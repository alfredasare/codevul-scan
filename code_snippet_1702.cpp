#include <linux/mutex.h>

static DEFINE_MUTEX(fdc_reset_mutex);

static void reset_interrupt(void)
{
	debugt(__func__, "");
	result();		/* get the status ready for set_fdc */

	mutex_lock(&fdc_reset_mutex);
	if (FDCS->reset) {
		pr_info("reset set in interrupt, calling %ps\n", cont->error);
		cont->error();	/* a reset just after a reset. BAD! */
	}
	mutex_unlock(&fdc_reset_mutex);

	cont->redo();
}