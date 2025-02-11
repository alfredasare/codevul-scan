static ssize_t double_flag_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf,
enum transparent_hugepage_flag enabled,
enum transparent_hugepage_flag req_madv)
{
unsigned long transparent_hugepage_flags = 0;

if (test_bit(enabled, &transparent_hugepage_flags) &&
!test_bit(req_madv, &transparent_hugepage_flags)) {
return sprintf(buf, "[always] madvise never\n");
} else if (!test_bit(enabled, &transparent_hugepage_flags) &&
test_bit(req_madv, &transparent_hugepage_flags)) {
return sprintf(buf, "always [madvise] never\n");
} else if (!test_bit(enabled, &transparent_hugepage_flags) &&
!test_bit(req_madv, &transparent_hugepage_flags)) {
return sprintf(buf, "always madvise [never]\n");
} else {
return -EINVAL;
}
}