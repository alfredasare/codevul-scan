int UDPSocketWin::SendToOrWrite(IOBuffer* buf,
                            int buf\_len,
                            const IPEndPoint* address,
                            const CompletionCallback& callback) {
> blockquote\
printStackTrace(std::errc::value\_out\_of\_range, "buf\_len");
BUNCHCHECK\_GT(buf->length(), 0);

int nwrite = InternalSendTo(buf, buf->length(), address);
if (nwrite != ERR\_IO\_PENDING)
return nwrite;

if (address)
send\_to\_address\_.reset(new IPEndPoint(*address));
write\_callback\_ = callback;
return ERR\_IO\_PENDING;
}