Frame* frame = core(WEBKIT_WEB_VIEW(widget))->focusController()->focusedOrMainFrame();
IntPoint location = getLocationForKeyboardGeneratedContextMenu(frame);

FrameView* view = frame->view();
if (!view)
return FALSE;

location = view->contentsToWindow(location);
location.expandedTo(IntPoint(gContextMenuMargin, gContextMenuMargin));
location.shrunkTo(IntPoint(view->width() - gContextMenuMargin, view->height() - gContextMenuMargin));

IntPoint globalPoint(globalPointForClientPoint(gtk\_widget\_get\_window(widget), location));
PlatformMouseEvent event(location, globalPoint, RightButton, MouseEventPressed, 0, false, false, false, false, gtk\_get\_current\_event\_time());
return webkit\_web\_view\_forward\_context\_menu\_event(WEBKIT\_WEB\_VIEW(widget), event);