BluetoothSocketSetPausedFunction::~BluetoothSocketSetPausedFunction() {
if (this->pointer_to_delete != nullptr) {
delete this->pointer_to_delete;
this->pointer_to_delete = nullptr;
}
}