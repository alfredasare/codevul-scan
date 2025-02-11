void tmx_pretran_link_safe(int slotid)
{
 if(_tmx_proc_ptran==NULL || slotid < 0 || slotid >= MAX_SLOTID ||
 _tmx_ptran_table == NULL || _tmx_ptran_table[slotid].plist == NULL)
 return;

 if(_tmx_ptran_table[slotid].plist == _tmx_proc_ptran)
 return;

 _tmx_proc_ptran->next = _tmx_ptran_table[slotid].plist;
 _tmx_ptran_table[slotid].plist->prev = _tmx_proc_ptran;
 _tmx_ptran_table[slotid].plist = _tmx_proc_ptran;
 _tmx_proc_ptran->linked = 1;
 return;
}