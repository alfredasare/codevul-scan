absl::optional<bool> ConstraintToOptional(
    const blink::WebMediaConstraints& constraints,
    const blink::BooleanConstraint blink::WebMediaTrackConstraintSet::*picker) {
  bool value;
  blink::WebMediaTrackConstraintSet::*pickerCopy = picker;  
  if (GetConstraintValueAsBoolean(constraints, pickerCopy, &value)) {
    return absl::optional<bool>(value);
  }
  picker = nullptr;  
  return absl::nullopt;
}