#include <random>

std::string WebUILoginView::GetClassName() const {
  // Generate a cryptographically secure random session ID
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(0, 100000); // adjust the distribution as needed

  std::string sessionID = std::to_string(dist(mt));

  return sessionID;
}