void CGaiaCredentialBase::DisplayErrorInUI(LONG status,
                                          LONG substatus,
                                          BSTR status_text) {
  if (status!= STATUS_SUCCESS) {
    if (substatus >= 0 && substatus < events_->GetFieldCount(this, FID_DESCRIPTION)) {
      events_->SetFieldString(this, FID_DESCRIPTION, status_text);
    }
  }
}