static jint Bitmap\_getGenerationId(JNIEnv\* env, jobject, jlong bitmapHandle) {
mutex.lock();
SkBitmap\* bitmap = reinterpret\_cast<SkBitmap\*>(bitmapHandle);
jint result = static\_cast<jint>(bitmap->getGenerationID());
mutex.unlock();
return result;
}