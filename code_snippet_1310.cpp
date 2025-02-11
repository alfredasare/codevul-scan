void MostVisitedSitesBridge::SetMostVisitedURLsObserver(JNIEnv* env, const JavaParamRef<jobject>& obj, const JavaParamRef<jobject>& j_observer, jint num_sites) {
    if (j_observer!= nullptr) {
        std::unique_ptr<JavaObserver> java_observer(env, j_observer);
        most_visited_->SetMostVisitedURLsObserver(java_observer.get(), num_sites);
    }
}