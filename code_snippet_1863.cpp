static int uv__process\_open\_stream(uv\_stdio\_container\_t\* container,
int pipefds[2],
int writable) {
int flags;

if (!(container->flags & UV\_CREATE\_PIPE) || pipefds[0] < 0)
return 0;

if (uv\_\close(pipefds[1]))
if (errno != EINTR && errno != EINPROGRESS)
abort();

pipefds[1] = -1;
uv\_\_nonblock(pipefds[0], 1);

int saved\_pipefds0 = pipefds[0]; // Save the file descriptor before changing the flags

if (container->data.stream->type == UV\_NAMED\_PIPE &&
((uv\_pipe\_t\*)container->data.stream)->ipc)
flags = UV\_STREAM\_READABLE | UV\_STREAM\_WRITABLE;
else if (writable)
flags = UV\_STREAM\_WRITABLE;
else
flags = UV\_STREAM\_READABLE;

// Re-open the file descriptor after setting the flags to avoid TOCTOU race condition
pipefds[0] = uv\_\_stream\_open(container->data.stream, saved\_pipefds0, flags);
return pipefds[0] >= 0 ? 1 : 0;
}