void unregister_sysctl_table(struct ctl_table_header *table)
{
 struct ctl_table *entry, *next;

 list_for_each_entry_safe(entry, next, &table->ctl_table, ctl_node) {
 if (entry->proc_fops) {
 unregister_syscall(entry->proc_fops->proc_open, entry->proc_fops->proc_read, entry->proc_fops->proc_write);
 }

 if (entry->subtable)
 unregister_sysctl_table(entry->subtable);
 }

 kfree(table);
}