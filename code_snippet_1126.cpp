c++
#include "base/memory/weak_ptr.h"

class NetworkDelegate;
typedef base::Callback<void(int)> AuthCallback;

class BlockingNetworkDelegate
{
public:
    BlockingNetworkDelegate()
        : retval_(ERR_IO_PENDING),
          callback_retval_(OK),
          auth_retval_(NetworkDelegate::AUTH_REQUIRED_RESPONSE_IO_PENDING),
          auth_callback_retval_(NetworkDelegate::AUTH_REQUIRED_RESPONSE_NO_ACTION)
    {
        weak_factory_.Init(this);
    }

    // ... other class members ...

private:
    int retval_;
    int callback_retval_;
    int auth_retval_;
    int auth_callback_retval_;
    base::WeakPtrFactory<BlockingNetworkDelegate> weak_factory_;
};