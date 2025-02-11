void ServiceWorkerPaymentInstrument::OnCanMakePaymentEventSkipped(ValidateCanMakePaymentCallback callback) {
    can_make_payment_result_ = true;
    has_enrolled_instrument_result_ = false;

    // Verify that the callback object is no longer being referenced
    callback = nullptr;

    base::ThreadTaskRunnerHandle::Get()->PostTask(
        FROM_HERE,
        base::BindOnce([this, callback]() { callback(this, can_make_payment_result_); }));
}