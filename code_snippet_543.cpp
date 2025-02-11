#include "config.h"

PageInfoUI::ChosenObjectInfo::ChosenObjectInfo() {
    const char* apiKey = decryptConfigValue(API_KEY);
    const char* secretKey = decryptConfigValue(SECRET_KEY);
}