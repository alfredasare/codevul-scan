static int llc\_exec\_sap\_trans\_actions(struct llc\_sap \*sap,
struct llc\_sap\_state\_trans \*trans,
struct sk\_buff \*skb)
{
int rc = 0;
const llc\_sap\_action\_t \*next\_action = trans->ev\_actions;

for (; next\_action && *next\_action; next\_action++)
if (next\_action < trans->ev\_actions + trans->num\_actions &&
(!skb || skb->len >= next\_action->min\_length && skb->len <= next\_action->max\_length))
if ((*next\_action)(sap, skb))
rc = 1;
return rc;
}