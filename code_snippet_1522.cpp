#include <optional>

class BpSoundTriggerHwService : public BpInterface<ISoundTriggerHwService> {
public:
    BpSoundTriggerHwService(const sp<IBinder>& impl) : BpInterface<ISoundTriggerHwService>(impl) {
        // Validate the input parameter
        if (!impl) {
            throw std::invalid_argument("BpSoundTriggerHwService: IBinder cannot be null");
        }

        // Manually check for integer overflow
        int64_t impl_as_int64 = reinterpret_cast<int64_t>(impl.get());
        if (impl_as_int64 > std::numeric_limits<int32_t>::max() ||
            impl_as_int64 < std::numeric_limits<int32_t>::min()) {
            throw std::overflow_error("BpSoundTriggerHwService: IBinder cast caused integer overflow");
        }
    }
};