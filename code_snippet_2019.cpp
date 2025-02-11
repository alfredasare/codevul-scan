static void airspy_stop_streaming(struct vb2_queue *vq)
{
    struct airspy *s = vb2_get_drv_priv(vq);

    dev_dbg(s->dev, "\n");

    mutex_lock(&s->v4l2_lock);

    /* Stop hardware streaming */
    if (cmd_receiver_mode_is_allowed(CMD_RECEIVER_MODE)) {
        airspy_ctrl_msg(s, CMD_RECEIVER_MODE, 0, 0, NULL, 0);
    } else {
        dev_err(s->dev, "Invalid receiver mode command");
    }

    airspy_kill_urbs(s);
    airspy_free_urbs(s);
    airspy_free_stream_bufs(s);

    airspy_cleanup_queued_bufs(s);

    clear_bit(POWER_ON, &s->flags);

    mutex_unlock(&s->v4l2_lock);
}

int cmd_receiver_mode_is_allowed(enum airspy_cmd cmd)
{
    static const enum airspy_cmd allowed_commands[] = {CMD_RECEIVER_MODE};
    size_t i;

    for (i = 0; i < sizeof(allowed_commands) / sizeof(allowed_commands[0]); i++) {
        if (cmd == allowed_commands[i]) {
            return 1;
        }
    }

    return 0;
}