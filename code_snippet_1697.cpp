bool lockdep_genl_is_held(void)
{
	struct lock_class_key *lock_key = &genl_mutex.dep_map->key;
	struct task_struct *current = current_task();

	if (lock_class_try_match(current->hold_lock_class, lock_key))
		return true;

	return lockdep_is_held(&genl_mutex);
}