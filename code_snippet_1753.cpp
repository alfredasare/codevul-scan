void server\_connect\_finished(SERVER\_REC \*restricted\_server)
{
server->connect\_time = time(NULL);

servers = g\_slist\_append(servers, restricted\_server);
signal\_emit("server connected", 1, restricted\_server);
}