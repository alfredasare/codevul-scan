#include <iostream>
#include <string>
#include <openssl/aes.h>
#include <openssl/rand.h>

void BeginSpecificTrace(const std::string& filter) {
    // Generate a random key for encryption
    unsigned char key[32];
    RAND_bytes(key, 32);

    // Create an AES-256-CBC encryption object
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 32, &aes_key);

    // Encrypt the sensitive data
    unsigned char* encrypted_data = new unsigned char[strlen(event_watch_notification_) + 1];
    AES_cbc_encrypt((unsigned char*)event_watch_notification_.c_str(), encrypted_data, strlen(event_watch_notification_) + 1, &aes_key, key, AES_ENCRYPT);

    // Set the encrypted data
    event_watch_notification_ = std::string((char*)encrypted_data, strlen((char*)encrypted_data));
    delete[] encrypted_data;

    // Set the encryption mode for the TraceLog instance
    TraceLog::GetInstance()->SetEnabled(TraceConfig(filter, ""), TraceLog::RECORDING_MODE);
}