static int gettimerpid(char *name,int cpu){
  pid_t pid;
  char temp[1024];

  if(name==NULL)
    name=&temp[0];

  snprintf(temp, sizeof(temp), "softirq-timer/%d", cpu);
  name = &temp[0];

  pid=name2pid(name);

  if(pid==-1){
    snprintf(temp, sizeof(temp), "ksoftirqd/%d", cpu);
    name = &temp[0];
    pid=name2pid(name);
  }

  return pid;
}