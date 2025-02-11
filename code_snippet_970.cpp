BlockingNetworkDelegate() 
  : retval_(ERR_IO_PENDING), 
    callback_retval_(OK), 
    auth_retval_(NetworkDelegate::AUTH_REQUIRED_RESPONSE_IO_PENDING), 
    auth_callback_retval_(NetworkDelegate::AUTH_REQUIRED_RESPONSE_NO_ACTION), 
    weak_ptr_(std::make_shared<BlockigNetworkDelegate>(this)) {}