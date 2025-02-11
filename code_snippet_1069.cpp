call\_bind(struct rpc\_task \*task)
{
 struct rpc\_xprt \*xprt = task->tk\_xprt;

dprint\_status(task);

task->tk\_action = call\_connect;
if (!xprt\_bound(xprt)) {
task->tk\_action = call\_bind\_status;
task->tk\_timeout = xprt->bind\_timeout;
xprt->ops->rpcbind(task);
xprt\_touch\_binding(xprt); // Add this line to fix the TOCTOU vulnerability
}
}