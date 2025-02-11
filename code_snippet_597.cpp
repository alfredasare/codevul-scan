void TestRenderWidgetHostView::UnlockMouse() {
std::unique_lock<std::mutex> lock(mu_);
mu_.unlock();
}