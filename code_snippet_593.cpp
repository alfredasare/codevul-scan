class MyClass {
private:
  const std::string errorMessage;
public:
  MyClass(const std::string& errMsg) : errorMessage(errMsg) {}
  virtual const std::string& GetError() const { return errorMessage; }
};