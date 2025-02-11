static void Bitmap_setPremultiplied(JNIEnv* env, jobject, jlong bitmapHandle,
                                   jboolean isPremul) {
    SkBitmap* bitmap = reinterpret_cast<SkBitmap*>(bitmapHandle);

    // Validate isPremul to avoid potential integer overflow or wraparound
    if (isPremul != JNI_TRUE && isPremul != JNI_FALSE) {
        jclass exceptionClass = env->FindClass("java/lang/IllegalArgumentException");
        env->ThrowNew(exceptionClass, "Invalid isPremul value");
        return;
    }

    if (!bitmap->isOpaque()) {
        if (isPremul == JNI_TRUE) {
            bitmap->setAlphaType(kPremul_SkAlphaType);
        } else {
            bitmap->setAlphaType(kUnpremul_SkAlphaType);
        }
    }
}