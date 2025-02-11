const unsigned long max_identifier = 1000; // Replace with the appropriate max value

void InspectorNetworkAgent::ScriptImported(unsigned long identifier,
                                           const String& source_string) {
    // Perform range checking on the identifier
    if (identifier >= max_identifier || identifier < 0) {
        // Handle the error, e.g., return an error or throw an exception
        return;
    }
    resources_data_->SetResourceContent(IdentifiersFactory::RequestId(identifier),
                                      source_string);
}