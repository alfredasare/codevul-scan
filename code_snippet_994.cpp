void SocketStream::RestartWithAuth(const AuthCredentials& credentials) {
  scoped_refptr<base::MessageLoopProxy> current_loop = base::MessageLoopProxy::current();
  if (current_loop && current_loop->Type() == base::MessageLoop::TYPE_IO) {
    DCHECK(proxy_auth_controller_.get());
    if (!socket_.get()) {
      DVLOG(1) << "Socket is closed before restarting with auth.";
      return;
    }

    proxy_auth_controller_->ResetAuth(credentials);

    current_loop->PostTask(FROM_HERE, base::Bind(&SocketStream::DoRestartWithAuth, this));
  } else {
    DVLOG(1) << "Current message loop is not available or not of type IO.";
  }
}