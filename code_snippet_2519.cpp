virtual ~DynamicMetadataProvider() {
    delete[] metadata; // Add this line to properly deallocate memory
}