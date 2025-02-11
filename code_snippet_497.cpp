vrrp_sgroup_t *vgroup = LIST_TAIL_DATA(vrrp_data->vrrp_sync_group);
pthread_mutex_init(&vgroup->script_master_mutex, NULL);

vrrp_gnotify_master_handler(vector_t *strvec)
{
	vrrp_sgroup_t *vgroup = LIST_TAIL_DATA(vrrp_data->vrrp_sync_group);

	pthread_mutex_lock(&vgroup->script_master_mutex);

	if (vgroup->script_master) {
		report_config_error(CONFIG_GENERAL_ERROR, "vrrp group %s: notify_master script already specified - ignoring %s", vgroup->gname, FMT_STR_VSLOT(strvec,1));
		pthread_mutex_unlock(&vgroup->script_master_mutex);
		return;
	}

	vgroup->script_master = set_vrrp_notify_script(strvec, 0);
	vgroup->notify_exec = true;

	pthread_mutex_unlock(&vgroup->script_master_mutex);
}

pthread_mutex_destroy(&vgroup->script_master_mutex);