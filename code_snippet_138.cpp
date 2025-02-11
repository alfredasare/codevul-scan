void EnterpriseEnrollmentScreen::Hide() {
  is_showing_ = false;
  if (actor_) {
    actor_->Hide();
  } else {
    // Handle the case where actor_ is null, e.g., by logging an error message.
    std::cerr << "Error: Actor pointer is null" << std::endl;
  }
}