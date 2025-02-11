static jint Bitmap_getGenerationId(JNIEnv* env, jobject, jlong bitmapHandle) {
    if (bitmapHandle == 0 ||!reinterpret_cast<SkBitmap*>(bitmapHandle)) {
        return -1; // or env->ThrowNew(env->FindClass("java/lang/NullPointerException"), "Invalid bitmap handle");
    }
    SkBitmap* bitmap = reinterpret_cast<SkBitmap*>(bitmapHandle);
    return static_cast<jint>(bitmap->getGenerationID());
}