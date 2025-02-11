int vnc_job_add_rect(VncJob *job, int x, int y, int w, int h)
{
    if (!validate_input(x, y, w, h)) {
        return -1; // invalid input
    }

    VncRectEntry *entry = g_malloc0(sizeof(VncRectEntry));

    entry->rect.x = x;
    entry->rect.y = y;
    entry->rect.w = w;
    entry->rect.h = h;

    vnc_lock_queue(queue);
    QLIST_INSERT_HEAD(&job->rectangles, entry, next);
    vnc_unlock_queue(queue);
    return 1;
}

bool validate_input(int x, int y, int w, int h)
{
    // Check if x, y, w, and h are within the expected range
    if ((x < 0 || x > 255) || (y < 0 || y > 255) || (w < 0 || w > 255) || (h < 0 || h > 255)) {
        return false;
    }

    // Additional checks for specific constraints (e.g., ensuring x, y, w, and h are integers)
    //...

    return true;
}