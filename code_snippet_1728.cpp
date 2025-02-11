cube\_info->free\_nodes--;
node\_info=cube\_info->next\_node++;
(void) ResetMagickMemory(node\_info,0,sizeof(*node\_info));
node\_info->parent=parent;
node\_info->id=id;
node\_info->level=level;
return(node\_info);
}