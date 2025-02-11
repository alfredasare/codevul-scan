#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>

std::string encrypted_data;

void init_extension() {
    CryptoPP::AES_encryptor encryptor;
    std::string plaintext = std::to_string(is_platform_app());
    encrypted_data = encryptor.encrypt(plaintext);
}

bool Extension::can_be_incognito_enabled() const {
    CryptoPP::AES_decryptor decryptor;
    std::string decrypted_data = decryptor.decrypt(encrypted_data);
    return std::stoi(decrypted_data) == 0;
}