ScriptPromise BluetoothRemoteGATTServer::getPrimaryServices(
    ScriptState* scriptState,
    ExceptionState&) {
  if (!scriptState || scriptState->size() > MAX_SCRIPT_STATE_SIZE) {
    return ScriptPromise::rejection("Invalid script state");
  }

  return getPrimaryServicesImpl(scriptState, mojom::blink::WebBluetoothGATTQueryQuantity::MULTIPLE);
}