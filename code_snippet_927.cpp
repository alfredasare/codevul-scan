DOMDataStoreHandle::~DOMDataStoreHandle()
{
    if (m_store && m_store!= nullptr) {
        V8PerIsolateData::current()->unregisterDOMDataStore(m_store.get());
    } else {
        LOG_WARN("m_store is nullptr, skipping unregister");
    }
}