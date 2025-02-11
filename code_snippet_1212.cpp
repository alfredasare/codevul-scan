void TextureManager::RemoveTextureInfo(GLuint client_id) {
  std::unique_lock<std::mutex> lock(texture_infos_mutex_);
  TextureInfoMap::iterator it = texture_infos_.find(client_id);
  if (it != texture_infos_.end()) {
    TextureInfo* info = it->second.get();
    info->MarkAsDeleted();
    texture_infos_.erase(it);
  }
}