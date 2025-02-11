COMPAT_SYSCALL_DEFINE2(sigaltstack,
const compat_stack_t __user *uss\_ptr,
compat\_stack\_t __user *uoss\_ptr)
{
stack\_t uss, uoss;
int ret;

if (uss\_ptr) {
comapt\_stack\_t uss32;
if (copy\_from\_user(&uss32, uss\_ptr, sizeof(compat\_stack\_t)))
return -EFAULT;

// Add size check for uss32
if (sizeof(uss32) > sizeof(stack\_t))
return -EINVAL;

uss.ss\_sp = compat\_ptr(uss32.ss\_sp);
uss.ss\_flags = uss32.ss\_flags;
uss.ss\_size = uss32.ss\_size;
}
ret = do\_sigaltstack(uss\_ptr ? &uss : NULL, &uoss,
compat\_user\_stack\_pointer());
if (ret >= 0 && uoss\_ptr) {
compat\_stack\_t old;
memset(&old, 0, sizeof(old));
old.ss\_sp = ptr\_to\_compat(uoss.ss\_sp);
old.ss\_flags = uoss.ss\_flags;
old.ss\_size = uoss.ss\_size;

// Ensure the correct size is used for copy\_to\_user
if (copy\_to\_user(uoss\_ptr, &old, sizeof(stack\_t)))
ret = -EFAULT;
}
return ret;
}

Note: I corrected the size used in copy\_to\_user to be consistent with the stack\_t size, as recommended.