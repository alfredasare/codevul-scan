#include <iostream>

class SendTabToSelfEntry {
public:
    ~SendTabToSelfEntry() {
        // Release any allocated resources here
        std::cout << "Destructor called" << std::endl;
    }
};

int main() {
    SendTabToSelfEntry* entry = new SendTabToSelfEntry();
    delete entry;
    return 0;
}