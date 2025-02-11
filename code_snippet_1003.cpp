void SetWindowRestoreOverrides(aura::Window* window,
                              const gfx::Rect& bounds_override,
                              ui::WindowShowState window_state_override) {
  if (!IsValidBoundsOverride(bounds_override) ||!IsValidWindowStateOverride(window_state_override)) {
    return; // invalid input data, exit early
  }

  gfx::Rect sanitized_bounds_override = SanitizeRect(bounds_override);
  ui::WindowShowState sanitized_window_state_override = SanitizeWindowStateOverride(window_state_override);

  window->SetProperty(kRestoreWindowStateTypeOverrideKey, ToWindowStateType(sanitized_window_state_override));
  window->SetProperty(kRestoreBoundsOverrideKey, new gfx::Rect(sanitized_bounds_override));
}