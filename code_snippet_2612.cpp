virtual status\_t storeMetaDataInBuffers(
node\_id node, OMX\_U32 port\_index, OMX\_BOOL enable) {
OMX\_PARAM\_PORTDEFINITION param;
memset(&param, 0, sizeof(param));
param.nPortIndex = port\_index;
remote()->getParameter(node, OMX\_IndexParamPortDefinition, &param, sizeof(param));

Parcel data, reply;
data.writeInterfaceToken(IOMX::getInterfaceDescriptor());
data.writeInt32((int32\_t)node);
data.writeInt32(param.nPortIndex); // Use the verified param.nPortIndex here
data.writeInt32((uint32\_t)enable);
remote()->transact(STORE\_META\_DATA\_IN\_BUFFERS, data, &reply);

status\_t err = reply.readInt32();
return err;
}