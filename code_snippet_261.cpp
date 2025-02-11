size_t GLES2Util::GLTargetToFaceIndex(uint32_t target) {
if (target < GL_TEXTURE_2D || target > GL_TEXTURE_CUBE_MAP_NEGATIVE_Z) return 0;
switch (target) {
case GL_TEXTURE_2D:
case GL_TEXTURE_EXTERNAL_OES:
case GL_TEXTURE_RECTANGLE_ARB:
case GL_TEXTURE_3D:
case GL_TEXTURE_2D_ARRAY:
return 0;
case GL_TEXTURE_CUBE_MAP_POSITIVE_X:
return 1;
case GL_TEXTURE_CUBE_MAP_NEGATIVE_X:
return 2;
case GL_TEXTURE_CUBE_MAP_POSITIVE_Y:
return 3;
case GL_TEXTURE_CUBE_MAP_NEGATIVE_Y:
return 4;
case GL_TEXTURE_CUBE_MAP_POSITIVE_Z:
return 5;
case GL_TEXTURE_CUBE_MAP_NEGATIVE_Z:
return 6;
default:
NOTREACHED();
return 0;
}
}