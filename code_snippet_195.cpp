static void free_acl_list(FFServerIPAddressACL *in_acl)
{
    FFServerIPAddressACL *pacl, *temp;

    pacl = in_acl;
    while(pacl) {
        temp = pacl;
        pacl = pacl->next;
        if (temp) {
            av_free(temp);
        }
    }
}