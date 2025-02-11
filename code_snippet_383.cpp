static int coolkey\_match\_card(sc\_card\_t \*card)
{
 int r;
 SC\_FUNC\_CALLED(card->ctx, SC\_LOG\_DEBUG\_VERBOSE);

 /* Prevent out-of-bounds read by checking the range of 'ops' */
 if ((unsigned long)card->ops &gt; (unsigned long)card->ctx-\&gt;func\_table\_end) {
 return 0;
 }

 card->ops-\>logout = NULL;

 r = coolkey\_select\_applet(card);
 return (r >= SC\_SUCCESS);
}