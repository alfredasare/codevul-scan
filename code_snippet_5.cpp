bool RenderBlock::hasMarginAfterQuirk(const RenderBox* child) const
{
    if (!child ||!child->isWritingModeRoot())
        return false;

    if (child->isHorizontalWritingMode() == isHorizontalWritingMode())
        return child->isRenderBlock()? toRenderBlock(child)->hasMarginBeforeQuirk() : child->style()->hasMarginBeforeQuirk();

    return false;
}