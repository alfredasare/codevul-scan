send\_cancel(struct TCP\_Server\_Info \*server, void \*buf, struct mid\_q\_entry \*mid)
{
if (server && server->ops && server->ops->send\_cancel)
return server->ops->send\_cancel(server, buf, mid);
return 0;
}