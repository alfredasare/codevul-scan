#include <openssl/rand.h>

bool NaClProcessHost::SendStart() {
  if (!enable_ipc_proxy_) {
    uint8_t sessionId[32];
    if (!RAND_bytes(sessionId, sizeof(sessionId))) {
      // handle error
    }
    std::string sessionStr((char*)sessionId, sizeof(sessionId));
    IPC::ChannelHandle(sessionStr);
  }
  return StartNaClExecution();
}