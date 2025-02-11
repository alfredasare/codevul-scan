void NavigationURLLoaderImpl::SetBeginNavigationInterceptorForTesting(
    const BeginNavigationInterceptor& interceptor) {
  DCHECK(!BrowserThread::IsThreadInitialized(BrowserThread::IO) ||
         BrowserThread::CurrentlyOn(BrowserThread::IO));
  DCHECK(!base::FeatureList::IsEnabled(network::features::kNetworkService));

  // Validate the size of the input data
  if (interceptor.size() > kMaxAllowedInterceptorSize) {
    LOG(ERROR) << "Invalid interceptor size: " << interceptor.size();
    return;
  }

  g_interceptor.Get() = interceptor;
}