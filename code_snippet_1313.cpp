bool BluetoothRemoteGATTServer::RemoveFromActiveAlgorithms(ScriptPromiseResolver* resolver) {
    if (!m_activeAlgorithms.contains(resolver)) {
        throw std::runtime_error("Resolver not found in active algorithms");
    }
    m_activeAlgorithms.remove(resolver);
    return true;
}