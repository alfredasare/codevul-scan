mk_list_foreach_safe(head, tmp, mk_vhost_fdt_key) {
    fdt = mk_list_entry(head, struct vhost_fdt_host, _head);
    if (fdt == NULL) {
        continue;
    }
    mk_list_del(&fdt->_head);
    mk_mem_free(fdt);
}

mk_mem_free(mk_vhost_fdt_key);
return 0;