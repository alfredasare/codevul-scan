void GLES2DecoderPassthroughImpl::UpdateTextureSizeFromTarget(GLenum target) {
GLenum texture\_type = TextureTargetToTextureType(target);
TextureTarget internal\_texture\_type = GLenumToTextureTarget(texture\_type);
BACKEND\_CHECK(internal\_texture\_type != TextureTarget::kUnkown);
BoundTexture& bound\_texture =
bound\_textures\_{\[static\_cast<size\_t>(internal\_texture\_type)\]}
[active\_texture\_unit\_];

// Check if the bound\_texture object is null before using it.
if (!bound\_texture) {
// Return or throw an exception.
// For example, you can return or throw an exception to handle the case where the
// bound\_texture object is null.
return; // or throw std::runtime\_error("Bound texture object is null.");
}

UpdateTextureSizeFromTexturePassthrough(bound\_texture->texture.get(),
bound\_texture->client\_id);
}