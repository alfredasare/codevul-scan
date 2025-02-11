void ServiceWorkerPaymentInstrument::OnCanMakePaymentEventSkipped(
    ValidateCanMakePaymentCallback callback) {
  can_make_payment_result_ = true;
  has_enrolled_instrument_result_ = false;
  auto shared_this = std::shared_ptr<ServiceWorkerPaymentInstrument>(this);
  base::ThreadTaskRunnerHandle::Get()->PostTask(
      FROM_HERE,
      base::BindOnce(std::move(callback), shared_this, can_make_payment_result_));
}

void ValidateCanMakePayment(
    const std::shared_ptr<ServiceWorkerPaymentInstrument>& payment_instrument,
    bool can_make_payment,
    bool has_enrolled_instrument) {
  // ...
}