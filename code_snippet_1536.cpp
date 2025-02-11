static void v9fs_fix_fid_paths(V9fsPDU *pdu, V9fsPath *olddir,
V9fsString *old\_name, V9fsPath *newdir,
V9fsString *new\_name)
{
V9fsFidState \*tfidp;
V9fsPath oldpath, newpath;
V9fsState \*s = pdu->s;
size\_t oldpath\_len;

v9fs\_path\_init(&oldpath);
v9fs\_path\_init(&newpath);
v9fs\_co\_name\_to\_path(pdu, olddir, old\_name->data, &oldpath);
v9fs\_co\_name\_to\_path(pdu, newdir, new\_name->data, &newpath);

/*
* Fixup fid's pointing to the old name to
* start pointing to the new name
*/
for (tfidp = s->fid\_list; tfidp; tfidp = tfidp->next) {
if (v9fs\_path\_is\_ancestor(&oldpath, &tfidp->path)) {
/* replace the name */
oldpath\_len = strlen(oldpath.data);
v9fs\_fix\_path(&tfidp->path, &newpath, oldpath\_len);
}
}
v9fs\_path\_free(&oldpath);
v9fs\_path\_free(&newpath);
}