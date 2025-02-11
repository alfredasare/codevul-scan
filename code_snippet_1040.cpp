void AdjustComponent(int delta, url::Component* component) {
  if (!component->is_valid())
    return;

  if (delta < std::numeric_limits<int>::min() || delta > std::numeric_limits<int>::max()) {
    // Handle error or reject input
    return;
  }

  int new_begin = component->begin + delta;
  if ((new_begin - delta) != component->begin && (new_begin < 0 || new_begin > std::numeric_limits<int>::max())) {
    // Handle error or reject input
    return;
  }

  component->begin = new_begin;
}