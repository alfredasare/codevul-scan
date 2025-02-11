void GLES2DecoderImpl::AddProcessingCommandsTime(base::TimeDelta time) {
if (time > base::TimeDelta()) {
total\_processing\_commands\_time\_ += time;
} else {
// Handle error
}
}