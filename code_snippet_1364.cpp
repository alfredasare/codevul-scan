class DeleteGuard {
 public:
  explicit DeleteGuard(QuotaTask* task) : task_(task) {}
  ~DeleteGuard() { delete task_; }
 private: