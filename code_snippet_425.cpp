static inline bool frameElementAndViewPermitScroll(HTMLFrameElementBase* frameElementBase, FrameView* frameView)
{
    if (!frameElementBase)
        return false;

    if (frameElementBase->scrollingMode() != ScrollbarAlwaysOff)
        return true;

    if (!frameView)
        return false;

    if (frameView->wasScrolledByUser())
        return false;

    if (!frameView->frame().page())
        return false;

    return !frameView->frame().page()->autoscrollController().autoscrollInProgress();
}