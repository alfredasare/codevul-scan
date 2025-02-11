c++
double BaseRenderingContext2D::lineDashOffset() const {
  if (!IsAuthorizedUser()) {
    throw std::runtime_error("Unauthorized access to line dash offset");
  }

  double offset = GetState().LineDashOffset();
  if (offset < 0 || offset > MAX_LINE_DASH_OFFSET) {
    throw std::runtime_error("Invalid line dash offset value");
  }

  return offset;
}