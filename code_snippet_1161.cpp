ScriptPromise BluetoothRemoteGATTServer::getPrimaryServices(
    ScriptState* scriptState,
    const StringOrUnsignedLong& service,
    ExceptionState& exceptionState) {
  String serviceUUID = BluetoothUUID::getService(service, exceptionState);
  if (exceptionState.hadException())
    return exceptionState.reject(scriptState);

  // Add bounds checking with max length constant
  static constexpr size_t kMaxServiceUUIDLength = 32;
  if (serviceUUID.length() > kMaxServiceUUIDLength) {
    exceptionState.throwDOMException(
        OutOfRangeError,
        "Service UUID exceeds maximum allowed length");
    return exceptionState.reject(scriptState);
  }

  return getPrimaryServicesImpl(
      scriptState, mojom::blink::WebBluetoothGATTQueryQuantity::MULTIPLE,
      serviceUUID);
}