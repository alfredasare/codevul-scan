void LayerWebKitThread::setNeedsDisplay()
{
    if (!m_tiler)
        return;

    const int MAX\_ALLOWED\_VALUE = 1000;

    int inputValue = getInputValue();
    if (inputValue < 0 || inputValue > MAX\_ALLOWED\_VALUE)
        return;

    m\_tiler->setNeedsDisplay(inputValue);
    setNeedsCommit();
}