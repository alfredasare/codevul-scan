bool FeatureInfo::IsWebGL2OrES3OrHigherContext() const {
    if (context_type_ == nullptr || *context_type_ < CONTEXT_TYPE_WEBGL2 || *context_type_ > CONTEXT_TYPE_ES3) {
        return false;
    }
    return IsWebGL2OrES3OrHigherContextType(*context_type_);
}