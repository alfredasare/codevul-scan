uint64_t GetTime() {
  base::Time now = base::Time::Now();
  return TimeToPPTime(now);
}