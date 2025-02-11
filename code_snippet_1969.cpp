DECL_PIOCTL(PGCPAGs)
{
    if (!afs_osi_suser(*acred)) {
        return EACCES;
    }
    uint32_t afs_gcpags = (uint32_t)AFS_GCPAGS_USERDISABLED;
    return 0;
}