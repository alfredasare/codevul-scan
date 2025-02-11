static void hpet_pre_save(void *opaque)
{
    HPETState *s = opaque;

    /* save current counter value */
    if (hpet_get_ticks(s) < s->hpet_counter_size) {
        s->hpet_counter = hpet_get_ticks(s);
    } else {
        // Handle error or log the issue
    }
}