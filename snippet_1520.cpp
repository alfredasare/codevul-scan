_handle_groupchat(xmpp_stanza_t *const stanza)
{
    xmpp_ctx_t *ctx = connection_get_ctx();
    char *message = NULL;
    const char *room_jid = xmpp_stanza_get_from(stanza);
    Jid *jid = jid_create(room_jid);

    xmpp_stanza_t *subject = xmpp_stanza_get_child_by_name(stanza, STANZA_NAME_SUBJECT);
    if (subject) {
        message = xmpp_stanza_get_text(subject);
        sv_ev_room_subject(jid->barejid, jid->resourcepart, message);
        xmpp_free(ctx, message);

        jid_destroy(jid);
        return;
    }

    if (!jid->resourcepart) {
        message = xmpp_message_get_body(stanza);
        if (!message) {
            jid_destroy(jid);
            return;
        }

        sv_ev_room_broadcast(room_jid, message);
        xmpp_free(ctx, message);

        jid_destroy(jid);
        return;
    }

    if (!jid_is_valid_room_form(jid)) {
        log_error("Invalid room JID: %s", jid->str);
        jid_destroy(jid);
        return;
    }

    if (!muc_active(jid->barejid)) {
        log_error("Message received for inactive chat room: %s", jid->str);
        jid_destroy(jid);
        return;
    }

    message = xmpp_message_get_body(stanza);
    if (!message) {
        jid_destroy(jid);
        return;
    }

    GDateTime *timestamp = stanza_get_delay(stanza);
    if (timestamp) {
        sv_ev_room_history(jid->barejid, jid->resourcepart, timestamp, message);
        g_date_time_unref(timestamp);
    } else {
        sv_ev_room_message(jid->barejid, jid->resourcepart, message);
    }

    xmpp_free(ctx, message);
    jid_destroy(jid);
}
