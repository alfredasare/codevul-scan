uid_t from_kuid(struct user_namespace *targ, kuid_t kuid)
{
	if (!targ || !kuid) {
		return NO_USER_ID;
	}

	uid_t min_id, max_id;
	size_t count;
	int ret = __get_user_ns_info(targ, &min_id, &max_id, &count);
	if (ret < 0) {
		return NO_USER_ID;
	}

	if (__kuid_val(kuid) < min_id || __kuid_val(kuid) > max_id) {
		return NO_USER_ID;
	}

	return map_id_up(&targ->uid_map, __kuid_val(kuid));
}