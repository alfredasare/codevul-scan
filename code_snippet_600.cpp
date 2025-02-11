c++
#define MAX_NAME_LENGTH 100

void InspectorPageAgent::PaintTiming(Document* document,
                                     const char* name,
                                     double timestamp) {
  if (name && strlen(name) < MAX_NAME_LENGTH) {
    char buffer[MAX_NAME_LENGTH + 1];
    strncpy(buffer, name, sizeof(buffer));
    GetFrontend()->lifecycleEvent(
        IdentifiersFactory::FrameId(document->GetFrame()), buffer, timestamp);
  } else {
    // Handle error condition, e.g., logging or throwing an exception
  }
}