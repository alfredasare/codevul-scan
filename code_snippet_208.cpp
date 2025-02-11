void ib\_uverbs\_qp\_event\_handler(struct ib\_event \*event, void \*context\_ptr)
{
struct ib\_uevent\_object \*uobj;

mutex\_lock(&qp\_uobject\_mutex);

/* for XRC target qp's, check that qp is live */
if (!event->element.qp->uobject) {
mutex\_unlock(&qp\_uobject\_mutex);
return;
}

uobj = container\_of(event->element.qp->uobject,
struct ib\_uevent\_object, uobject);

ib\_uverbs\_async\_handler(context\_ptr, uobj->uobject.user\_handle,
event->event, &uobj->event\_list,
&uobj->events\_reported);

mutex\_unlock(&qp\_uobject\_mutex);
}