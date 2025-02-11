c++
bool BaseRenderingContext2D::IsValidBlendMode(SkBlendMode op) {
  return op >= SkBlendMode::kZero && op <= SkBlendMode::kLastEnum;
}