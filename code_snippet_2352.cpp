fb->len = (fb->len > 0) ? fb->len : FILEWBUF\_INIT\_LEN;
wp = reallocarray(fb->wbuf, fb->len, sizeof(wchar\_t));