int audit_set_loginuid(kuid_t loginuid)
{
    struct task_struct *task = current;
    int oldsessionid, sessionid = -1;
    kuid_t oldloginuid;
    int rc;

    oldloginuid = audit_get_loginuid(current);
    oldsessionid = audit_get_sessionid(current);

    rc = audit_set_loginuid_perm(loginuid);
    if (rc)
        goto out;

    /* are we setting or clearing? */
    if (uid_valid(loginuid))
        sessionid = atomic_inc_return(&session_id);

    task->sessionid = sessionid;
    task->loginuid = loginuid;
out:
    audit_log_set_loginuid(oldloginuid, loginuid, oldsessionid, sessionid, rc);
    if (rc!= 0)
        // Handle error
        //...
    return rc;
}