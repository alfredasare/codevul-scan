#include <linux/drm.h>
#include <linux/mutex.h>

void vc4_drm_mode_crtc_helper_funcs(struct drm_crtc *crtc)
{
    struct vc4_dev *vc4 = to_vc4_dev(crtc->dev);
    mutex_init(&vc4->job_lock, &vc4->power_lock, 0, NULL);
}

void vc4_gem_init(struct drm_device *dev)
{
    struct vc4_dev *vc4 = to_vc4_dev(dev);

    INIT_LIST_HEAD(&vc4->bin_job_list);
    INIT_LIST_HEAD(&vc4->render_job_list);
    INIT_LIST_HEAD(&vc4->job_done_list);
    INIT_LIST_HEAD(&vc4->seqno_cb_list);

    spin_lock_init(&vc4->job_lock);

    INIT_WORK(&vc4->hangcheck.reset_work, vc4_reset_work);
    setup_timer(&vc4->hangcheck.timer, vc4_hangcheck_elapsed, (unsigned long)dev);

    INIT_WORK(&vc4->job_done_work, vc4_job_done_work);

    vc4_drm_mode_crtc_helper_funcs(dev->crtc);
    mutex_init(&vc4->power_lock, &vc4->power_lock, 0, NULL);
}