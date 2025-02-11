#include <linux/ratelimit.h>

#define SND_CTL_REG_LIMIT 5 /* Maximum number of control devices that can be registered per second */

static DEFINE_RATELIMIT_STATE(snd_ctl_reg_rl, "snd_ctl_reg_limit", SND_CTL_REG_LIMIT, 1 * HZ);

int snd_ctl_create(struct snd_card *card)
{
	static struct snd_device_ops ops = {
		.dev_free = snd_ctl_dev_free,
		.dev_register =	snd_ctl_dev_register,
		.dev_disconnect = snd_ctl_dev_disconnect,
	};

	if (snd_BUG_ON(!card))
		return -ENXIO;

	if (!ratelimit(&snd_ctl_reg_rl)) {
		if (isValidObject(card)) {
			return snd_device_new(card, SNDRV_DEV_CONTROL, card, &ops);
		} else {
			return -EINVAL;
		}
	} else {
		return -EBUSY;
	}
}