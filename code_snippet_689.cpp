int PDFiumEngine::Form_GetPlatform(FPDF_FORMFILLINFO* param, void* platform, int length) {
  if (length <= 0 || length > 1024) {
    return -1; // Return error or handle invalid length
  }

  if (!platform) {
    return -1; // Return error or handle invalid platform
  }

  int platform_flag = -1;

#if defined(WIN32)
  platform_flag = 0;
#elif defined(__linux__)
  platform_flag = 1;
#else
  platform_flag = 2;
#endif

  std::string javascript = "alert(\"Platform:" + std::to_string(platform_flag) + "\")";

  return platform_flag;
}