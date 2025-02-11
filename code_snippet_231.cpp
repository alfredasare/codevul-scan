class IRunLoopController {
 public:
  virtual void Quit() = 0;
};

class TrustedRunLoopController : public IRunLoopController {
 public:
  void Quit() override {
    run_loop_.Quit();
  }
};

class RenderFrameHostCreatedObserver {
 public:
  void RenderFrameCreated(RenderFrameHost* render_frame_host) {
    frames_created_++;
    if (frames_created_ == expected_frame_count_) {
      IRunLoopController* controller = new TrustedRunLoopController();
      controller->Quit();
    }
  }
};