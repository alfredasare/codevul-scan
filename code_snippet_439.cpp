vrrp_gnotify_master_handler(vector_t *strvec)
{
    vrrp_sgroup_t *vgroup = LIST_TAIL_DATA(vrrp_data->vrrp_sync_group);
    if (vgroup->script_master) {
        report_config_error(CONFIG_GENERAL_ERROR, "vrrp group %s: notify_master script already specified - ignoring %s", vgroup->gname, FMT_STR_VSLOT(strvec, 1));
        return;
    }
    char *script = set_vrrp_notify_script(strvec, 0);
    if (!script) {
        return;
    }
    vgroup->script_master = script;
    vgroup->notify_exec = true;
}

char *set_vrrp_notify_script(vector_t *strvec, int len)
{
    char script[256]; // Assuming a maximum script length of 256 bytes
    size_t script_len;

    if (len > sizeof(script) - 1) {
        report_config_error(CONFIG_GENERAL_ERROR, "Script too long");
        return NULL;
    }

    script_len = snprintf(script, sizeof(script), "%.*s", len, strvec->buf);
    if (script_len < 0) {
        report_config_error(CONFIG_GENERAL_ERROR, "Failed to format script");
        return NULL;
    }

    script[script_len] = '\0'; // Ensure null termination

    return strdup(script);
}