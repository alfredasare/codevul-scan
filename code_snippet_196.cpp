static void free_acl_list(FFServerIPAddressACL *in_acl)
{
    FFServerIPAddressACL *pacl, *pacl2;

    pacl = in_acl;
    while(pacl) {
        pacl2 = pacl;
        pacl = pacl->next;
        if (pacl2 != NULL) {
            av_freep(pacl2);
        }
    }
}