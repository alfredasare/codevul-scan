static const char \*set_server\_alias(cmd\_parms \*cmd, void \*dummy,
const char \*arg)
{
if (!cmd->server->names) {
return "ServerAlias only used in <VirtualHost>";
}

while (\*arg) {
char \*\*item = (char \*\*)apr\_palloc(cmd->pool, sizeof(char \*));
char \*name = ap\_getword\_conf(cmd->pool, &arg);

if (ap\_is\_matchexp(name)) {
apr\_array\_push(cmd->server->wild\_names, item);
}
else {
apr\_array\_push(cmd->server->names, item);
}

\*item = name;
}

return NULL;
}