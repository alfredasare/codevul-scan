int UDPSocketWin::GetPeerAddress(IPEndPoint* address) const {
  DCHECK(CalledOnValidThread());
  DCHECK(address);
  if (!is_connected())
    return ERR_SOCKET_NOT_CONNECTED;

  if (!remote_address_.get()) {
    SockaddrStorage storage;
    int result = getpeername(socket_, storage.addr, &storage.addr_len);
    if (result == SOCKET_ERROR) {
      return MapSystemError(WSAGetLastError());
    }
    scoped_ptr<IPEndPoint> address(new IPEndPoint());
    if (!address->FromSockAddr(storage.addr, storage.addr_len)) {
      return ERR_ADDRESS_INVALID;
    }
    remote_address_.reset(address.release());
  }

  *address = *remote_address_;
  return OK;
}