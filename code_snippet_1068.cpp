DOMDataStoreHandle::~DOMDataStoreHandle()
{
    if (m_store && m_store->is_valid()) // Check if m_store is valid
        V8PerIsolateData::current()->unregisterDOMDataStore(m_store.get());
}