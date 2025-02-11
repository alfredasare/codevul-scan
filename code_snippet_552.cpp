bool XDisplayExists() {
    Display* display = GetXDisplay();
    if (display!= NULL && strlen(display->name) <= sizeof(display->name)) {
        return true;
    }
    return false;
}