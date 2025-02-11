BluetoothSocketSetPausedFunction* pausedSocket = nullptr;
try {
    pausedSocket = new BluetoothSocketSetPausedFunction();
    //... use the object...
} catch (...) {
    delete pausedSocket;
}