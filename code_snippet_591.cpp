c++
const std::map<GLenum, GLfloat> VALID_PNAMES = {
  {GL_MAX_TEXTURE_LOD_BIAS, capabilities_.max_texture_lod_bias}
};

bool GLES2Implementation::GetFloatvHelper(GLenum pname, GLfloat* params) {
  if (VALID_PNAMES.find(pname) == VALID_PNAMES.end()) {
    return false;
  }
  *params = VALID_PNAMES[pname];
  return true;
}