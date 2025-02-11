static jobject android_net_wifi_get_driver_version(JNIEnv *env, jclass cls, jint iface) {
    JNIHelper helper(env);
    int buffer_length = 256;
    char *buffer = (char *)malloc(buffer_length);
    if (!buffer) return NULL;
    memset(buffer, 0, buffer_length);
    wifi_interface_handle handle = getIfaceHandle(helper, cls, iface);

    __android_log_print(ANDROID_LOG_VERBOSE, "Android_Net_Wifi", "get_driver_version: handle = %p", handle);

    if (handle == 0) {
        return NULL;
    }

    wifi_error result = hal_fn.wifi_get_driver_version(handle, buffer, buffer_length);

    if (result == WIFI_SUCCESS) {
        __android_log_print(ANDROID_LOG_VERBOSE, "Android_Net_Wifi", "get_driver_version: buffer = %p, length = %d", buffer, buffer_length);
        JNIObject<jstring> driver_version = helper.newStringUTF(buffer);
        free(buffer);
        return driver_version.detach();
    } else {
        __android_log_print(ANDROID_LOG_ERROR, "Android_Net_Wifi", "Fail to get driver version");
        free(buffer);
        return NULL;
    }
}