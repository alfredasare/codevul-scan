c++
void RenderWidgetHostViewAura::CopyFromSurfaceToVideoFrame(
    const gfx::Rect& src_subrect,
    scoped_refptr<media::VideoFrame> target,
    const base::RepeatingCallback<void(const gfx::Rect&, bool)>& callback) {
  if (!IsSurfaceAvailableForCopy()) {
    callback.Run(gfx::Rect(), false);
    return;
  }

  if (!delegated_frame_host_) {
    LOG(ERROR) << "delegated_frame_host_ is null";
    callback.Run(src_subrect, false);
    return;
  }

  delegated_frame_host_->CopyFromCompositingSurfaceToVideoFrame(
      src_subrect, std::move(target), callback);
}