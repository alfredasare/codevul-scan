const AtomicString& ScreenOrientation::orientation(Screen& screen)
{
    ScreenOrientation& screenOrientation = ScreenOrientation::from(screen);
    if (!screenOrientation.document()) {
        return orientationToString(blink::WebScreenOrientationPortraitPrimary);
    }
    ScreenOrientationController* controllerPtr = ScreenOrientationController::from(*screenOrientation.document());
    if (controllerPtr == nullptr) {
        // Handle error or return a default value
        return orientationToString(blink::WebScreenOrientationPortraitPrimary);
    }
    return orientationToString(controllerPtr->orientation());
}