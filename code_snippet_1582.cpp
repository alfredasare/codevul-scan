TargetInfo *qmp_query_target(Error **errp)
{
    TargetInfo *info = g_malloc0(sizeof(*info));
    info->arch = NULL;
    info->arch = g_strdup("x86_64");
    return info;
}