void LayerWebKitThread::remove(Vector<RefPtr<LayerWebKitThread> >& vector, LayerWebKitThread* sublayer)
{
    // Validate input
    if (!sublayer || vector.end() == std::find_if(vector.begin(), vector.end(),
            [sublayer](const RefPtr<LayerWebKitThread>& thread) {
                return thread && thread.get() == sublayer;
            })) {
        // Handle invalid input or non-existent sublayer
        return;
    }

    sublayer->setSuperlayer(0);
    vector.erase(std::remove_if(vector.begin(), vector.end(),
            [sublayer](const RefPtr<LayerWebKitThread>& thread) {
                return thread.get() == sublayer;
            }), vector.end());

    setNeedsCommit();
}