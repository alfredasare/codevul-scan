Virtual status\_t encryptNative(
const sp<GraphicBuffer>& graphicBuffer,
size\_t offset, size\_t size, uint32\_t streamCTR,
uint64\_t \*outInputCTR, void \*outData) {
Parcel data, reply;
data.writeInterfaceToken(IHDCP::getInterfaceDescriptor());
data.writeBuffer(graphicBuffer->handle, size); // write the necessary size only
data.writeInt32(offset);
data.writeInt32(static\_cast<int32\_t>(size));
data.writeInt32(streamCTR);
remote()->transact(HDCP\_ENCRYPT\_NATIVE, data, &reply);

status\_t err = reply.readInt32();

if (err != OK) {
\*outInputCTR = 0;
return err;
}

\*outInputCTR = reply.readInt64();
reply.read(outData, size);

return err;
}