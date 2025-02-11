c++
#include <stdexcept>

// ...

void AudioSource::rampVolume(
    int32_t startFrame, int32_t rampDurationFrames,
    uint8_t *data, size_t bytes) {

    const int32_t kShift = 14;
    int32_t fixedMultiplier = safe_div((startFrame << kShift), rampDurationFrames);
    const int32_t nChannels = mRecord->channelCount();
    int32_t stopFrame = startFrame + bytes / sizeof(int16_t);
    int16_t *frame = (int16_t *) data;
    if (stopFrame > rampDurationFrames) {
        stopFrame = rampDurationFrames;
    }

    while (startFrame < stopFrame) {
        if (nChannels == 1) { // mono
            frame[0] = (frame[0] * fixedMultiplier) >> kShift;
            ++frame;
            ++startFrame;
        } else { // stereo
            frame[0] = (frame[0] * fixedMultiplier) >> kShift;
            frame[1] = (frame[1] * fixedMultiplier) >> kShift;
            frame += 2;
            startFrame += 2;
        }

        if ((startFrame & 3) == 0) {
            fixedMultiplier = safe_div((startFrame << kShift), rampDurationFrames);
        }
    }
}

int32_t safe_div(int32_t dividend, int32_t divisor) {
    if (divisor == 0) {
        throw std::invalid_argument("Divisor cannot be zero");
    }
    int64_t result = static_cast<int64_t>(dividend) / static_cast<int64_t>(divisor);
    if (result > INT32_MAX || result < INT32_MIN) {
        throw std::overflow_error("Integer overflow in division");
    }
    return static_cast<int32_t>(result);
}