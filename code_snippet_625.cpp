void IPCThreadState::decStrongHandle(int32_t handle)
{
    IPCThreadState* threadState = getThreadState(); 
    LOG_REMOTEREFS("IPCThreadState::decStrongHandle(%d)\n", handle);
    threadState->decStrongHandle(handle); 
    mOut.writeInt32(BC_RELEASE);
    mOut.writeInt32(handle);
}