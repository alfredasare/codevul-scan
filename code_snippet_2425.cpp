#include <string.h>

const char* allowedChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";

bool isValidName(const char* name) {
    for (int i = 0; name[i]; i++) {
        if (strchr(allowedChars, name[i]) == NULL) {
            return false;
        }
    }
    return true;
}

android::SoftOMXComponent *createSoftOMXComponent(
    const char *name, const OMX_CALLBACKTYPE *callbacks,
    OMX_PTR appData, OMX_COMPONENTTYPE **component) {
    if (!isValidName(name)) {
        return NULL;
    }
    return new android::SoftGSM(name, callbacks, appData, component);
}