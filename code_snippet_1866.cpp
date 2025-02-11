bool V4L2JpegEncodeAccelerator::EncodedInstance::CreateBuffers(
gfx::Size coded\_size,
size\_t output\_buffer\_size) {
if (!coded\_size.IsEmpty() && output\_buffer\_size > 0) {
if (!SetOutputBufferFormat(coded\_size, output\_buffer\_size)) {
return false;
}

if (!SetInputBufferFormat(coded\_size)) {
return false;
}

if (!RequestInputBuffers()) {
return false;
}

if (!RequestOutputBuffers()) {
return false;
}

return true;
}
return false;
}