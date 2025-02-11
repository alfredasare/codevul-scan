class MyClass {
 public:
  MyClass() : should_expire_(false) {}
  void AllowExpiry() { should_expire_ = true; }
 private:
  bool should_expire_;
};

int main() {
  MyClass obj;
  obj.AllowExpiry();
  return 0;
}