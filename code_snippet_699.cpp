void RenderView::didStopLoading() {
  if (!is_loading_) {
    DLOG(WARNING) << "DidStopLoading called while not loading";
    return;
  }

  is_loading_ = false;

  Send(new ViewHostMsg_DidStopLoading(routing_id_));

  if (load_progress_tracker_ != nullptr)
    load_progress_tracker_->DidStopLoading();
  else {
    DLOG(ERROR) << "load_progress_tracker_ is null. Unable to call DidStopLoading.";
  }

  FOR_EACH_OBSERVER(RenderViewObserver, observers_, DidStopLoading());
}