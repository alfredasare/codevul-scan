static const auto kMaxLinkClicksPerMinute = 5;  // Set maximum link clicks per minute as needed
static base::Time last_click_time = base::Time::Now();
base::TimeDelta interval = base::Time::Now() - last_click_time;

if (interval.InMinutes() < 1) {
    int allowed_clicks = (interval.InMinutes() * kMaxLinkClicksPerMinute).floor();
    if (allowed_clicks <= 0) {
        return;
    }
}
last_click_time = base::Time::Now();

BEREKTAIN_EQ(link_, source);
if (GetDelegate()->LinkClicked(ui::DispositionFromEventFlags(event_flags)))
    RemoveSelf();