void PluginModule::SetBroker(PluginDelegate::Broker* broker) {
  DCHECK(broker!= nullptr);  // Check if the input pointer is not NULL
  broker_ = broker;
}