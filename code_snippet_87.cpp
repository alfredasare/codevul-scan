get_counters(const struct xt\_table\_info \*t, struct xt\_counters counters[])
{
 struct ip6t\_entry \*iter;
 unsigned int cpu;
 unsigned int i;

 for\_each\_possible\_cpu(cpu) {
 seqcount\_t \*s = &per\_cpu(xt\_recseq, cpu);

 i = 0;
 xt\_entry\_foreach(iter, t->entries, t->size) {
 struct xt\_counters \*tmp;
 u6