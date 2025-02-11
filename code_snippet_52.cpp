void DiceResponseHandler::DiceTokenFetcher::OnTimeout() {
  RecordDiceFetchTokenResult(kFetchTimeout);

  if (!gaia_auth_fetcher_.empty()) {
    gaia_auth_fetcher_.reset();
  }

  if (timeout_closure_!= nullptr) {
    timeout_closure_.Cancel();
  }

  if (dice_response_handler_!= nullptr) {
    dice_response_handler_->OnTokenExchangeFailure(this, GoogleServiceAuthError(GoogleServiceAuthError::REQUEST_CANCELED));
  }
}