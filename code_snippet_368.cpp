virtual status_t createInputSurface(
    node_id node, OMX_U32 port_index,
    sp<IGraphicBufferProducer> *bufferProducer, MetadataBufferType *type) {
    Parcel data, reply;
    status_t err;

    // Verify and sanitize input values
    if (node > std::numeric_limits<OMX_U32>::max()) {
        ALOGE("Invalid node ID: %d", node);
        return BAD_VALUE;
    }
    if (port_index > std::numeric_limits<OMX_U32>::max()) {
        ALOGE("Invalid port index: %d", port_index);
        return BAD_VALUE;
    }

    data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
    data.writeInt32((int32_t)node);
    err = remote()->transact(CREATE_INPUT_SURFACE, data, &reply);
    if (err!= OK) {
        ALOGW("binder transaction failed: %d", err);
        return err;
    }

    int negotiatedType = reply.readInt32();
    if (type!= NULL) {
        *type = (MetadataBufferType)negotiatedType;
    }

    err = reply.readInt32();
    if (err!= OK) {
        return err;
    }

    *bufferProducer = IGraphicBufferProducer::asInterface(reply.readStrongBinder());
    return err;
}