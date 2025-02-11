void WebBluetoothServiceImpl::GattCharacteristicValueChanged(
    device::BluetoothAdapter* adapter,
    device::BluetoothRemoteGattCharacteristic* characteristic,
    const std::vector<uint8_t>& value) {
  if (!base::Contains(characteristic_id_to_service_id_,
                      characteristic->GetIdentifier())) {
    return;
  }

  // Limit the number of elements in the value vector to prevent buffer over-reads or writes
  constexpr size_t kMaxValueElements = 64;
  if (value.size() > kMaxValueElements) {
    LOG(WARNING) << "Number of value elements exceeded the maximum allowed value: "
                 << value.size();
    return;
  }

  // Validate the elements in the value vector
  for (const uint8_t element : value) {
    if (element < 0 || element > 255) {  // Example: limit the value to the range of uint8_t
      LOG(WARNING) << "Invalid value element: " << element;
      return;
    }
  }

  if (!base::ThreadTaskRunnerHandle::Get()->PostTask(
          FROM_HERE,
          base::BindOnce(
              &WebBluetoothServiceImpl::NotifyCharacteristicValueChanged,
              weak_ptr_factory_.GetWeakPtr(), characteristic->GetIdentifier(),
              value))) {
    LOG(WARNING) << "No TaskRunner.";
  }
}