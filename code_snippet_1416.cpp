static inline void hwsim\_set\_chanctx\_magic(struct ieee80211\_chanctx\_conf \*c)
{
	if (c && c->drv\_priv && 
	    sizeof(struct hwsim\_chanctx\_priv) >= sizeof(c->drv\_priv)) {
		struct hwsim\_chanctx\_priv \*cp = (void *)c->drv\_priv;
		cp->magic = HWSIM\_CHANCTX\_MAGIC;
	}
}