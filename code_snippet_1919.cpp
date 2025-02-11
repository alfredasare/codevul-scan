PassRefPtr<RTCSessionDescriptionDescriptor> RTCPeerConnectionHandlerChromium::localDescription(String& errorMessage)
{
    if (!m\_webHandler)
    {
        errorMessage = "m\_webHandler is not initialized";
        return 0;
    }

    if (!m\_webHandler->isValidInput())
    {
        errorMessage = "Invalid input";
        return 0;
    }

    return m\_webHandler->localDescription();
}