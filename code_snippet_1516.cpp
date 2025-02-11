void ImageResource::AllClientsAndObserversRemoved() {
> const bool should_reset_animation = !ThreadHeap::WillObjectBeLazilySwept(this);
  CHECK(is_during_finish_as_error_ || !GetContent()->HasImage() ||
        !ErrorOccurred());
  if (should_reset_animation) {
    Platform::Current()->CurrentThread()->GetWebTaskRunner()->PostTask(
        FROM_HERE, WTF::Bind(&ImageResourceContent::DoResetAnimation,
                             WrapWeakPersistent(GetContent())));
  } else {
    GetContent()->DoResetAnimation();
  }
  if (multipart_parser_)
    multipart_parser_->Cancel();
  Resource::AllClientsAndObserversRemoved();
}