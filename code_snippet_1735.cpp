vc4\_gem\_init(struct drm\_device \*dev)
{
struct vc4\_dev \*vc4 = to\_vc4\_dev(dev);

INIT\_LIST\_HEAD(&vc4->bin\_job\_list);
INIT\_LIST\_HEAD(&vc4->render\_job\_list);
INIT\_LIST\_HEAD(&vc4->job\_done\_list);
INIT\_LIST\_HEAD(&vc4->seqno\_cb\_list);
spin\_lock\_init(&vc4->job\_lock);

INIT\_WORK(&vc4->hangcheck.reset\_work, vc4\_reset\_work);
setup\_timer(&vc4->hangcheck.timer,
vc4\_hangcheck\_elapsed,
(unsigned long)dev);

vc4->hangcheck.elapsed = 0;
vc4->hangcheck.active = 0;

INIT\_WORK(&vc4->job\_done\_work, vc4\_job\_done\_work);

mutex\_init(&vc4->power\_lock);
}