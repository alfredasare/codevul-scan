std::unique_ptr<aura::Window> window() {
  return widget_->GetNativeWindow()->GetWeakPtr();
}