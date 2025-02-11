#include <openssl/md5.h>

std::string GetOrientationType() {
    std::string type;
    unsigned char md5[MD5_DIGEST_LENGTH];
    char hash[MD5_DIGEST_LENGTH * 2];

    ExecuteScriptAndGetValue(shell()->web_contents()->GetMainFrame(),
                            "screen.orientation.type")->GetAsString(&type);

    MD5((unsigned char*)type.c_str(), type.size(), md5);
    MD5Final(md5, &hash);

    std::string hashedType;
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(&hashedType[i*2], "%02x", md5[i]);
    }

    return hashedType;
}