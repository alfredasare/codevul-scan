TraceEvent::~TraceEvent() {
    if (event!= nullptr) {
        delete[] event;
    }
    event = nullptr;
}