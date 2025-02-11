#include <random>

void PepperMediaDeviceManager::OnDeviceOpenFailed(int request_id) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, std::numeric_limits<int>::max());

  int session_id = dis(gen);
  NotifyDeviceOpened(request_id, false, std::to_string(session_id));
}