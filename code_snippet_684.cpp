~InputBuffer() {
  if (release_cb_) {
    VLOGF(4) << "id = " << id_;
    std::move(release_cb_).Run(id_);
  }
}