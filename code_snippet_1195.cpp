void PDFiumEngine::Form_KillTimer(FPDF_FORMFILLINFO* param, int timer_id) {
  PDFiumEngine* engine = static_cast<PDFiumEngine*>(param);
  if (engine!= nullptr) {
    auto it = engine->timers_.find(timer_id);
    if (it!= engine->timers_.end()) {
      // Release any resources associated with the timer
      it->second->ReleaseResources();
    }
    engine->timers_.erase(it);
  }
}