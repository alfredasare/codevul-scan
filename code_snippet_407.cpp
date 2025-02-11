const int MAX_EXPECTED_COUNT = 100; // Replace this value with the appropriate maximum

void OnNotificationBalloonCountObserver::CheckBalloonCount() {
  if (count_ < 0 || count_ > MAX_EXPECTED_COUNT) {
    return;
  }

  bool balloon_count_met = AreActiveNotificationProcessesReady() &&
      static_cast<int>(collection_->GetActiveBalloons().size()) == count_;

  if (balloon_count_met && automation_) {
    AutomationJSONReply(automation_,
                        reply_message_.release()).SendSuccess(NULL);
  }

  if (balloon_count_met || !automation_) {
    collection_->set_on_collection_changed_callback(base::Closure());
    delete this;
  }
}