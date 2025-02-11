connection\_edge\_end\_errno(edge\_connection\_t \*conn)
{
uint8\_t reason;
tor\_assert(conn);

// Use getrandom() instead of errno_to\_stream\_end\_reason()
if (getrandom(&reason, sizeof(reason), 0) != sizeof(reason)) {
reason = STREAM_END\_REASON\_ERROR;
}

return connection\_edge\_end(conn, reason);
}