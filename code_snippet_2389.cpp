void WebRtcAudioRenderer::SetVolume(float volume) {
> if (state_ == UNINITIALIZED || !sink_)
return;

base::AutoLock auto\_lock(lock_);
sink_->SetVolume(volume);
}