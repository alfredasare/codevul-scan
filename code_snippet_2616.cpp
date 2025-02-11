Fixed code:

    virtual void* allocateNewSpace(size_t& size)
    {
        void* allocatedMemory = malloc(size);
        if (!allocatedMemory) {
            throw std::bad_alloc();
        }
        return allocatedMemory;
    }