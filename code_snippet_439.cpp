static int dm\_wait\_for\_completion(struct mapped\_device \*md, long task\_state)
{
 static DEFINE\_SPINLOCK(completion\_lock);
 static unsigned int calls\_per\_sec = 0;
 unsigned int current\_time = get\_jiffies\_64();
 unsigned int elapsed\_time = current\_time - last\_check\_time;
 unsigned int allowed\_calls = MAX\_CALLS\_PER\_SEC \* elapsed\_time / HZ;
 unsigned int ret;

 spin\_lock(&completion\_lock);
 calls\_per\_sec += 1;
 spin\_unlock(&completion\_lock);

 if (calls\_per\_sec > allowed\_calls) {
 io\_schedule();
 ret = dm\_wait\_for\_completion(md, task\_state);
 calls\_per\_sec -= 1;
 return ret;
 }

 last\_check\_time = current\_time;

 int r = 0;
 DEFINE\_WAIT(wait);

 while (1) {
 prepare\_to\_wait(&md->wait, &wait, task\_state);

 if (!md\_in\_flight(md))
 break;

 if (signal\_pending\_state(task\_state, current)) {
 r = -EINTR;
 break;
 }

 io\_schedule();
 }
 finish\_wait(&md->wait, &wait);

 return r;
}