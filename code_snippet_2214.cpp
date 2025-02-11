virtual void cancelBuffer(int buf, const sp<Fence>& fence) {
    Parcel data, reply;

    // Validate the buf integer
    if (buf < 0 || buf > INT32_MAX) {
        LOG_ERROR("Invalid buffer index");
        return;
    }

    // Validate and serialize the fence object
    Parcel fenceParcel;
    fenceParcel.writeInterfaceToken(Fence::getInterfaceDescriptor());
    fenceParcel.write(*fence.get());
    fenceParcel.setDataPosition(0);
    fenceParcel.setDataSize(fenceParcel.dataSize());

    data.writeInterfaceToken(IGraphicBufferProducer::getInterfaceDescriptor());
    data.writeInt32(buf);
    data.write(fenceParcel);
    remote()->transact(CANCEL_BUFFER, data, &reply);
}