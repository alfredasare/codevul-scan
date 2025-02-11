GraphicsSurfaceToken GraphicsContext3DPrivate::graphicsSurfaceToken() const
{
    if (!isValidUser() ||!isAuthorized()) {
        throw std::runtime_error("Unauthorized access");
    }

    if (!validateRequestParameters()) {
        throw std::invalid_argument("Invalid request parameters");
    }

    return m_graphicsSurface->exportToken();
}