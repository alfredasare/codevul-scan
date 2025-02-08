XRenderHasDepths (Display *dpy)
{
    int	s;

    for (s = 0; s < ScreenCount (dpy); s++)
    {
	CARD32		    depths = 0;
	CARD32		    missing;
	Screen		    *scr = ScreenOfDisplay (dpy, s);
	int		    d;

	for (d = 0; d < scr->ndepths; d++)
	    depths |= DEPTH_MASK(scr->depths[d].depth);
	missing = ~depths & REQUIRED_DEPTHS;
	if (missing)
	{
	    DepthCheckRec   dc, **dp;
	    XErrorHandler   previousHandler;

	    /*
	     * Ok, this is ugly.  It should be sufficient at this
	     * point to just return False, but Xinerama is broken at
	     * this point and only advertises depths which have an
	     * associated visual.  Of course, the other depths still
	     * work, but the only way to find out is to try them.
	     */
	    dc.dpy = dpy;
	    dc.missing = 0;
	    dc.serial = XNextRequest (dpy);
	    _XLockMutex(_Xglobal_lock);
	    dc.next = depthChecks;
	    depthChecks = &dc;
	    _XUnlockMutex (_Xglobal_lock);
	    /*
	     * I suspect this is not really thread safe, but Xlib doesn't
	     * provide a lot of options here
	     */
	    previousHandler = XSetErrorHandler (XRenderDepthCheckErrorHandler);
	    /*
	     * Try each missing depth and see if pixmap creation succeeds
	     */
	    for (d = 1; d <= 32; d++)
		/* don't check depth 1 == Xcursor recurses... */
		if ((missing & DEPTH_MASK(d)) && d != 1)
		{
		    Pixmap  p;
		    p = XCreatePixmap (dpy, RootWindow (dpy, s), 1, 1, d);
		    XFreePixmap (dpy, p);
		}
	    XSync (dpy, False);
	    XSetErrorHandler (previousHandler);
	    /*
	     * Unhook from the list of depth check records
	     */
	    _XLockMutex(_Xglobal_lock);
	    for (dp = &depthChecks; *dp; dp = &(*dp)->next)
	    {
		if (*dp == &dc)
		{
		    *dp = dc.next;
		    break;
		}
	    }
	    _XUnlockMutex (_Xglobal_lock);
	    if (dc.missing)
		return False;
	}
    }
    return True;
}
