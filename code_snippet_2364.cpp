#include <mutex>
#include <chrono>

std::mutex g_interceptor_mutex;
std::pair<const BeginNavigationInterceptor&, std::mutex> g_interceptor;

void NavigationURLLoaderImpl::SetBeginNavigationInterceptorForTesting(
    const BeginNavigationInterceptor& interceptor) {
  DCHECK(!BrowserThread::IsThreadInitialized(BrowserThread::IO) ||
         BrowserThread::CurrentlyOn(BrowserThread::IO));
  DCHECK(!base::FeatureList::IsEnabled(network::features::kNetworkService));

  std::unique_lock<std::mutex> lock(g_interceptor_mutex);
  g_interceptor.first = interceptor;
}