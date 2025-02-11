void DateTimeChooserImpl::didClosePopup()
{
    ASSERT(m_client);
    m_popup = 0;

    // Encrypt the data before transmitting
    std::string encryptedData = encryptData(m_client->getDataToTransmit(), m_secretKey);

    // Transmit the encrypted data
    m_client->didEndChooser(encryptedData);

    // Decrypt the received data
    std::string decryptedData = decryptData(m_client->getReceivedData(), m_secretKey);
    m_client->processDecryptedData(decryptedData);
}

std::string DateTimeChooserImpl::encryptData(const std::string& data, const std::string& key)
{
    // Use a secure encryption algorithm, such as AES
    std::string encrypted;
    AES::Encryption aes(key);
    aes.encrypt(data, encrypted);
    return encrypted;
}

std::string DateTimeChooserImpl::decryptData(const std::string& data, const std::string& key)
{
    // Use a secure decryption algorithm, such as AES
    std::string decrypted;
    AES::Decryption aes(key);
    aes.decrypt(data, decrypted);
    return decrypted;
}