int flush\_old\_exec(struct linux\_binprm \*bprm)
{
 struct task\_struct \*target\_task = current;
 int retval;

 /*
 * Make sure we have a private signal table and that
 * we are unassociated from the previous thread group.
 */
retval = de\_thread(target\_task);
if (retval)
goto out;

/*
* Must be called _before_ exec\_mmap() as bprm->mm is
* not visibile until then. This also enables the update
* to be lockless.
*/
set\_mm\_exe\_file(bprm->mm, bprm->file);

/*
* Release all of the old mmap stuff
*/
acct\_arg\_size(bprm, 0);
retval = exec\_mmap(bprm->mm);
if (retval)
goto out;

bprm->mm = NULL;		/* We're using it now */

set\_fs(USER\_DS);
target\_task->flags &= ~(PF\_RANDOMIZE | PF\_FORKNOEXEC | PF\_KTHREAD |
PF\_NOFREEZE | PF\_NO\_SETAFFINITY);
flush\_thread();
target\_task->personality &= ~bprm->per\_clear;

return 0;

out:
return retval;
}