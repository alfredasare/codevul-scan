static int blkcg\_reset\_stats(struct cgroup\_subsys\_state \*css,
struct cftype \*cftype, u64 val)
{
struct blkcg \*blkcg = css\_to\_blkcg(css);
struct blkcg\_gq \*blkg;
int i;

mutex\_lock(&blkcg\_pol\_mutex);
spin\_lock\_irq(&blkcg->lock);

/*
* Note that stat reset is racy - it doesn't synchronize against
* stat updates. This is a debug feature which shouldn't exist
* anyway. If you get hit by a race, retry.
*/
hlist\_for\_each\_entry(blkg, &blkcg->blkg\_list, blkcg\_node) {
if (blkg->stat\_ios.nr\_ios != 0) { // Add null check before division
blkg\_rwstat\_reset(&blkg->stat\_bytes);
blkg\_rwstat\_reset(&blkg->stat\_ios);
}

    for (i =