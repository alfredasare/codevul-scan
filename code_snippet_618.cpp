static void timerfd_setup_cancel(struct timerfd_ctx *ctx, int flags)
{
	bool might\_cancel = (ctx->clockid == CLOCK\_REALTIME ||
		 ctx->clockid == CLOCK\_REALTIME\_ALARM) &&
		(flags & TFD\_TIMER\_ABSTIME) && (flags & TFD\_TIMER\_CANCEL\_ON\_SET);

	spin\_lock(&cancel\_lock);
	if (might\_cancel && !ctx->might\_cancel) {
		ctx->might\_cancel = true;
		list\_add\_rcu(&ctx->clist, &cancel\_list);
	} else if (!might\_cancel && ctx->might\_cancel) {
		timerfd\_remove\_cancel(ctx);
	}
	spin\_unlock(&cancel\_lock);
}