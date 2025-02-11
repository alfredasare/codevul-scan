void EnterpriseEnrollmentScreen::Hide() {
    is_showing_ = false;
    if (actor_) {
        actor_->HideSecurely();
    }
}