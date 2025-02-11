Virtual status\_t createInputSurface(node\_id node, OMX\_U32 port\_index,
sp<IGraphicBufferProducer>\* bufferProducer, MetadataBufferType \*type) {
 Parcel data, reply;
 status\_t err;

data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
data.writeInt32((int32\_t)node);
data.writeInt32(port\_index);

err = remote()->transact(CREATE\_INPUT\_SURFACE, data, &reply);
if (err != OK || !reply.readInt32()) {
ALOGW("binder transaction failed: %d", err);
return err;
}

int negotiatedType = reply.readInt32();
if (type != NULL) {
*type = (MetadataBufferType)negotiatedType;
}

*bufferProducer = IGraphicBufferProducer::asInterface(
reply.readStrongBinder());

return OK;
}