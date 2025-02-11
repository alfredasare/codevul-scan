#include "chrome/common/safe_strings.h"

base::string16 ScreenLayoutObserverTest::GetDisplayNotificationText() const {
  const message_center::Notification* notification = GetDisplayNotification();
  return notification ? SafeStrings::SanitizeForHtml(notification->title())
                      : base::string16();
}