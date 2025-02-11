void SetWindowRestoreOverrides(aura::Window* window,
const gfx::Rect& bounds_override,
ui::WindowShowState window_state_override) {
if (bounds_override.IsEmpty()) {
window->ClearProperty(kRestoreWindowStateTypeOverrideKey);
window->ClearProperty(kRestoreBoundsOverrideKey);
return;
}

// Limit the width and height to 10000 to prevent potential buffer overflow.
int max_width = 10000;
int max_height = 10000;

if (bounds_override.width() > max_width) {
bounds_override.set_width(max_width);
}

if (bounds_override.height() > max_height) {
bounds_override.set_height(max_height);
}

window->SetProperty(kRestoreWindowStateTypeOverrideKey,
ToWindowStateType(window_state_override));
window->SetProperty(kRestoreBoundsOverrideKey,
new gfx::Rect(bounds_override));
}