static gboolean webkit_web_view_popup_menu_handler(GtkWidget* widget)
{
    Frame* frame = core(WEBKIT_WEB_VIEW(widget))->focusController()->focusedOrMainFrame();
    IntPoint location = getLocationForKeyboardGeneratedContextMenu(frame);

    if (!frame ||!frame->view()) {
        return FALSE;
    }

    FrameView* view = frame->view();
    if (!view) {
        return FALSE;
    }

    if (location.x < 0 || location.y < 0 || location.x >= view->width() || location.y >= view->height()) {
        return FALSE;
    }

    location = view->contentsToWindow(location);
    location.expandedTo(IntPoint(gContextMenuMargin, gContextMenuMargin));
    location.shrunkTo(IntPoint(std::min(location.x, view->width() - gContextMenuMargin), std::min(location.y, view->height() - gContextMenuMargin)));

    IntPoint globalPoint(globalPointForClientPoint(gtk_widget_get_window(widget), location));
    PlatformMouseEvent event(location, globalPoint, RightButton, MouseEventPressed, 0, false, false, false, false, gtk_get_current_event_time());
    return webkit_web_view_forward_context_menu_event(WEBKIT_WEB_VIEW(widget), event);
}