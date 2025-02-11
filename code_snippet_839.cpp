void XFreeFeedbackList(XFeedbackState *list)
{
    if (list!= NULL) {
        size_t size = sizeof(XFeedbackState);
        if (list < (XFeedbackState *) 0 || list >= (XFeedbackState *)((char *)list + size)) {
            /* handle invalid index */
        } else {
            XFree((char *) list);
        }
    }
}