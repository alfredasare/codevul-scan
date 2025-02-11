c++
status_t CameraSource::isCameraColorFormatSupported(const CameraParameters& params) {
    if (params.get(CameraParameters::KEY_VIDEO_FRAME_FORMAT).isEmpty()) {
        return BAD_VALUE;
    }

    mColorFormat = getColorFormat(params.get(CameraParameters::KEY_VIDEO_FRAME_FORMAT));
    if (mColorFormat == -1 || mColorFormat >= NUM_COLOR_FORMATS) {
        return BAD_VALUE;
    }
    return OK;
}