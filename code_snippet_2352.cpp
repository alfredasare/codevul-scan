void LayerWebKitThread::remove(Vector<RefPtr<LayerWebKitThread> >& vector, LayerWebKitThread* sublayer)
{
    if (!sublayer) {
        return; // Handle invalid input
    }

    size_t foundIndex = vector.find(sublayer);
    if (foundIndex == Vector<RefPtr<LayerWebKitThread>>::npos) {
        return; // Not found
    }

    vector.erase(foundIndex);
    setNeedsCommit();
}