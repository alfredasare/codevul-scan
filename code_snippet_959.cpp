void XFreeFeedbackList(XFeedbackState *list)
{
    if (list != NULL) {
        XFree((char *)list);
    }
}