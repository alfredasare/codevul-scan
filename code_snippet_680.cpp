void post\_init\_entity\_util\_avg(struct sched\_entity *se)
{
 struct cfs\_rq *cfs\_rq = NULL;
 struct sched\_avg *sa = NULL;
 long cpu\_scale = 0;
 long cap = 0;

if (!se) {
pr\_err("Error: se is NULL\n");
return;
}

cfs\_rq = cfs\_rq\_of(se);
if (!cfs\_rq) {
pr\_err("Error: cfs\_rq is NULL\n");
return;
}

sa = &se->avg;
cpu\_scale = arch\_scale\_cpu\_capacity(NULL, cpu\_of(rq\_of(cfs\_rq)));
cap = (long)(cpu\_scale - cfs\_rq->avg.util\_avg) / 2;

...
}