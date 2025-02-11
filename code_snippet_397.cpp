class InitialLoadObserver {
 public:
  InitialLoadObserver(GDataFileSystemInterface* file_system,
                       const base::Closure& callback)
      : file_system(file_system), callback(callback) {}

 private:
  GDataFileSystemInterface* file_system;
  const base::Closure& callback;
};