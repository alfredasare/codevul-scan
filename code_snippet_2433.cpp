virtual status_t storeMetaDataInBuffers(node_id node, OMX_U32 port_index, OMX_BOOL enable) {
    Parcel data, reply;
    data.writeInterfaceToken(IOMX::getInterfaceDescriptor());

    // Verify input parameters
    if (node > MAX_NODE_ID || port_index > MAX_PORT_INDEX) {
        return ERROR_INVALID_PARAMETER;
    }

    data.writeInt32((int32_t)node);
    data.writeInt32(port_index);
    data.writeInt32((uint32_t)enable);

    remote()->transact(STORE_META_DATA_IN_BUFFERS, data, &reply);

    status_t err = reply.readInt32();
    return err;
}