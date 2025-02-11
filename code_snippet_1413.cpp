#include <limits>

const int kNonCharacter1 = std::numeric_limits<int>::min() + 1;
const int kNonCharacter3 = std::numeric_limits<int>::min() + 4;

bool IsNonCharacter(int character) {
    if (character < kNonCharacter3 && character > kNonCharacter1) {
        return true;
    }
    return false;
}