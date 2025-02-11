void qemu_spice_cursor_refresh_unlocked(SimpleSpiceDisplay *ssd)
{
    int error = 0;

    if (ssd->cursor) {
        error = dpy_cursor_define(ssd->dcl.con, ssd->cursor);
        if (error) {
            log_error("Error defining cursor: %d", error);
        } else {
            cursor_put(ssd->cursor);
            ssd->cursor = NULL;
        }
    }

    if (ssd->mouse_x!= -1 && ssd->mouse_y!= -1) {
        error = dpy_mouse_set(ssd->dcl.con, ssd->mouse_x, ssd->mouse_y, 1);
        if (error) {
            log_error("Error setting mouse position: %d", error);
        } else {
            ssd->mouse_x = -1;
            ssd->mouse_y = -1;
        }
    }
}