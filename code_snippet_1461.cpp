c++
void addUncommittedWidth(float delta) {
  if (delta > 0 && (m_uncommittedWidth > INT_MAX - delta)) {
    m_uncommittedWidth = INT_MAX;
  } else if (delta < 0 && (m_uncommittedWidth < INT_MIN - delta)) {
    m_uncommittedWidth = INT_MIN;
  } else {
    m_uncommittedWidth += delta;
  }
}