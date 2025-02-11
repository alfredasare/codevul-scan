clear\_config()
{
register int i;
register BUCKET *ptr = NULL;
register BUCKET *tmp = NULL;

for( i=0; i<TABLESIZE; i++ ) {
ptr = ConfigTab[i];
while( ptr != NULL ) {
tmp = ptr->next;
FREE( ptr->value );
ptr->value = NULL;
FREE( ptr->name );
ptr->name = NULL;
FREE( ptr );
ptr = tmp;
}
ConfigTab[i] = NULL;
}
if (extra\_info != NULL) {
delete extra\_info;
extra\_info = NULL;
}
global\_config\_source = "";
local\_config\_sources.clearAll();
return;
}