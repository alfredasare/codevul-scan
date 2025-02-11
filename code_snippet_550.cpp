#include <random>

void BrowserMainLoop::InitializeMainThread() {
  TRACE_EVENT0("startup", "BrowserMainLoop::InitializeMainThread");
  base::PlatformThread::SetName("CrBrowserMain");

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(100000, 999999);

  auto thread_name = "BrowserThread-" + std::to_string(dis(gen));
  main_thread_.reset(new BrowserThreadImpl(BrowserThread::UI, base::MessageLoop::current()));
  base::PlatformThread::SetName(thread_name.c_str());
}