const sp<IMediaPlayerService>& MediaMetadataRetriever::getService()
{
    Mutex::Autolock lock(sServiceLock);
    const std::set<String16> allowedServices = {"media.player",...}; // add other allowed services here
    String16 serviceName = "media.player"; // input from user
    if (allowedServices.find(serviceName) == allowedServices.end()) {
        ALOGE("Invalid service name: %s", serviceName.c_str());
        return nullptr;
    }

    serviceName = PathSanitizer::sanitize(serviceName);
    if (serviceName.empty()) {
        ALOGE("Invalid service name: %s", serviceName.c_str());
        return nullptr;
    }

    Mutex::Autolock lock(sServiceLock);
    if (sService == 0) {
        sp<IServiceManager> sm = defaultServiceManager();
        sp<IBinder> binder;
        do {
            binder = sm->getService(serviceName);
            if (binder!= 0) {
                break;
            }
            ALOGW("MediaPlayerService not published, waiting...");
            usleep(500000); // 0.5 s
        } while (true);
        if (sDeathNotifier == NULL) {
            sDeathNotifier = new DeathNotifier();
        }
        binder->linkToDeath(sDeathNotifier);
        sService = interface_cast<IMediaPlayerService>(binder);
    }
    ALOGE_IF(sService == 0, "no MediaPlayerService!?");
    return sService;
}