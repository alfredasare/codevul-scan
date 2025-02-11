void PPB_URLLoader_Impl::InstanceWasDeleted() {
    loader_.reset();
    loader_.reset(); // Set loader_ to nullptr explicitly
}