/* Validate the input */
	if (IS_ERR_OR_NULL(loginuid)) {
		pr_err("Invalid loginuid\n");
		return -EINVAL;
	}

	oldloginuid = audit_get_loginuid(current);
	oldsessionid = audit_get_sessionid(current);

	rc = audit_set_loginuid_perm(loginuid);
	if (rc)
		goto out;

	/* are we setting or clearing? */
	if (uid_valid(loginuid))
		sessionid = (unsigned int)atomic_inc_return(&session_id);

	task->sessionid = sessionid;
	task->loginuid = loginuid;
out:
	audit_log_set_loginuid(oldloginuid, loginuid, oldsessionid, sessionid, rc);
	return rc;