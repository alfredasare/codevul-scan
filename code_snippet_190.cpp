void ArthurOutputDev::updateLineDash(GfxState *state)
{
    int dashLength = state->getDashLength();
    int dashSpace = state->getDashSpace();

    if (dashLength > INT_MAX - dashSpace || dashLength < INT_MIN + dashSpace) {
        // Handle the overflow/underflow case
        //...
    }

    uint32_t totalLength = static_cast<uint32_t>(dashLength) + dashSpace;
    //...
}