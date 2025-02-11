static bool might_cancel_static = false;

static void timerfd_setup_cancel(struct timerfd_ctx *ctx, int flags)
{
    if ((ctx->clockid == CLOCK_REALTIME || 
         ctx->clockid == CLOCK_REALTIME_ALARM) &&
        (flags & TFD_TIMER_ABSTIME) && (flags & TFD_TIMER_CANCEL_ON_SET)) {
        if (!might_cancel_static) {
            might_cancel_static = true;
            spin_lock(&cancel_lock);
            list_add_rcu(&ctx->clist, &cancel_list);
            spin_unlock(&cancel_lock);
        }
    } else if (might_cancel_static) {
        timerfd_remove_cancel(ctx);
    }
}