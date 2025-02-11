virtual void cancelBuffer(int buf, const sp<Fence>& fence) {
> Parcel data, reply;
>     data.writeInterfaceToken(IGraphicBufferProducer::getInterfaceDescriptor());
>     data.writeInt32(buf);
>-    data.write(*fence.get());
>+    if (fence != nullptr) {
>+        data.write(*fence.get());
>+    } else {
>+        data.writeInt32(-1); // Use a default value or error code if fence is null
>+    }
>     remote()->transact(CANCEL_BUFFER, data, &reply);
> }