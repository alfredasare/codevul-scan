RendererWebIDBCursorImpl* cursor = cursors_[cursor\_id];
if (!cursor) {
LOG(ERROR) << "Null RendererWebIDBCursorImpl object detected";
return;
}
cursor->SetPrefetchData(keys, primary\_keys, values);

WebIDBCallbacks* callbacks = pending\_callbacks_.Lookup(response\_id);
if (!cursor) {
LOG(ERROR) << "Null RendererWebIDBCursorImpl object detected";
return;
}
cursor->CachedContinue(callbacks);
pending\_callbacks_.Remove(response\_id);