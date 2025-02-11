status_t CameraSource::isCameraColorFormatSupported(
    const CameraParameters& params) {
    mColorFormat = getColorFormat(params.get(CameraParameters::KEY_VIDEO_FRAME_FORMAT));
    if (mColorFormat == -1) {
        return STATUS_ERROR_UNKNOWN; // Generic error message
    }
    return OK;
}