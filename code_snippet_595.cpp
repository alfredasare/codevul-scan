void av_register_hwaccel(AVHWAccel *hwaccel)
{
    AVHWAccel *p = last_hwaccel;
    hwaccel->next = NULL;
    while(p && p != hwaccel && avpriv_atomic_ptr_cas((void * volatile *)(&p->next), NULL, hwaccel))
        p = p->next;
    if (p == NULL) {
        last_hwaccel = &hwaccel->next;
        return;
    }
    // handle the error case where the hwaccel is already registered
    // ...
}