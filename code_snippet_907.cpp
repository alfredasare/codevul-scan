void AdjustComponent(int delta, url::Component* component) {
  if (!component->is_valid())
    return;

  if (delta < 0) {
    LOG(ERROR) << "Invalid delta value: " << delta;
    return;
  }

  DCHECK(delta >= 0);
  component->begin += delta;
}