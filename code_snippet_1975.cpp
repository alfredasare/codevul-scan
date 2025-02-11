__exit exit\_misc\_binfmt(struct binfmt\_misc *misc\_format,
struct file\_system\_type *bm\_fs\_type)
{
if (!misc\_format\_is\_valid(misc\_format)) {
pr\_err("Invalid misc\_format\n");
return;
}

unregister\_binfmt(misc\_format);

if (!bm\_fs\_type\_is\_valid(bm\_fs\_type)) {
pr\_err("Invalid bm\_fs\_type\n");
return;
}

unregister\_filesystem(bm\_fs\_type);
}