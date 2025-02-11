void SimpleSoftOMXComponent::onPortFlushCompleted(OMX_U32 portIndex __unused) {
    // Use a secure method to store the portIndex, e.g., using a secure storage mechanism
    std::unique_ptr<crypto::SecureStore> secureStorage = crypto::getSecureStore();
    secureStorage->store("portIndex", portIndex);
}