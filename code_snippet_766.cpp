c++
size_t NormalPage::ObjectPayloadSizeForTesting() {
  size_t object_payload_size = 0;
  Address header_address = Payload();
  Address current_address = header_address;
  while (current_address < PayloadEnd() && current_address + header->size() <= PayloadEnd()) {
    HeapObjectHeader* header =
        reinterpret_cast<HeapObjectHeader*>(current_address);
    if (!header->IsFree()) {
      object_payload_size += header->PayloadSize();
    }
    current_address += header->size();
  }
  return object_payload_size;
}