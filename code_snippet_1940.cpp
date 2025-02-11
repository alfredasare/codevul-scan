const AtomicString& ScreenOrientation::orientation(Screen& screen)
{
    ScreenOrientation& screenOrientation = ScreenOrientation::from(screen);
    if (!screenOrientation.document()) {
        return orientationToString(blink::WebScreenOrientationPortraitPrimary);
    }
    ScreenOrientationController& controller = ScreenOrientationController::from(*screenOrientation.document());
    blink::WebScreenOrientation orientationValue = controller.orientation();
    if (!isValidOrientation(orientationValue)) {
        return orientationToString(blink::WebScreenOrientationPortraitPrimary);
    }
    return orientationToString(orientationValue);
}

bool isValidOrientation(blink::WebScreenOrientation orientation) {
    return orientation >= blink::WebScreenOrientationPortrait && 
           orientation <= blink::WebScreenOrientationLandscapeSecondary;
}