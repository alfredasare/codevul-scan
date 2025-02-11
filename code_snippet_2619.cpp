c++
bool CSPSourceList::allowHash(const CSPHashValue& hashValue) const
{
    // Validate the input hashValue
    if (hashValue.size() != SHA256_DIGEST_LENGTH) {
        return false;
    }

    return m_hashes.contains(hashValue);
}