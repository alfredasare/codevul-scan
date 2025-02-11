c++
class HeadlessDevToolsClientChangeWindowStateTest
    : public HeadlessDevToolsClient {
 public:
  void OnSetWindowState(
      std::unique_ptr<browser::SetWindowBoundsResult> result) {
    auto bound_method = base::Bind(&HeadlessDevToolsClientChangeWindowStateTest::OnGetWindowState,
                                   base::RetainedRef(this));
    GetWindowBounds(std::move(bound_method));
  }

 private:
  void OnGetWindowState(const gfx::Rect& bounds) { ... }
};