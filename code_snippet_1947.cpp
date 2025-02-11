#include <memory>

class CrosLibrary {
public:
    // ...
    class SyslogsLibrary {
    public:
        // ...
    };

    class SyslogsLibraryImpl {
    public:
        // ...
        void SetImpl(SyslogsLibrary* library, bool own) {
            //