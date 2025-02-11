is_v3_ckpt(const char *name) {
> const char *format = "cluster: %d.proc: %d.subproc: %d";
   int cluster, proc, subproc;

   cluster = grab_val(name, "cluster");
   proc = grab_val(name, ".proc");
   subproc = grab_val(name, ".subproc");

   if (proc < 0) {
      return cluster_exists(cluster);
   } else {
      return proc_exists(cluster, proc);
   }
}