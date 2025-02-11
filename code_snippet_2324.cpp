class BaseClass {
public:
    virtual ~BaseClass() { }  // Make the base class destructor virtual
};

class DynamicMetadataProvider : public BaseClass {
public:
    virtual ~DynamicMetadataProvider() {
        BaseClass::~BaseClass();  // Call the base class destructor
    }
};