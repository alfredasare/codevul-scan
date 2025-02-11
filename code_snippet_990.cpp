ScriptPromise BluetoothRemoteGATTServer::getPrimaryServices(
    ScriptState* scriptState,
    const StringOrUnsignedLong& service,
    ExceptionState& exceptionState) {
  std::string serviceUUID;
  if (!validateServiceUUID(service, exceptionState)) {
    return exceptionState.reject(scriptState);
  }

  serviceUUID = boost::lexical_cast<std::string>(service);
  if (serviceUUID.length() > MAX_SERVICE_UUID_LENGTH) {
    exceptionState.reject(scriptState, "Invalid service UUID length");
    return;
  }

  return getPrimaryServicesImpl(scriptState, mojom::blink::WebBluetoothGATTQueryQuantity::MULTIPLE, serviceUUID);
}

bool validateServiceUUID(const StringOrUnsignedLong& service, ExceptionState& exceptionState) {
  // Implement a validation function to check the format and length of the service UUID
  // Return false if the input is invalid
}