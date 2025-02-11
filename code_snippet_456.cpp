#include <cstring>

const int kMaxFeatureLength = 64; // Adjust this value based on your requirement

GLboolean GLES2Implementation::EnableFeatureCHROMIUM(const char* feature) {
  GPU_CLIENT_SINGLE_THREAD_CHECK();
  GPU_CLIENT_LOG("[" << GetLogPrefix() << "] glEnableFeatureCHROMIUM("
                     << feature << ")");
  TRACE_EVENT0("gpu", "GLES2::EnableFeatureCHROMIUM");

  if (std::strlen(feature) > kMaxFeatureLength) {
    GPU_CLIENT_LOG("Error: Feature name too long. Maximum length is "
                   << kMaxFeatureLength);
    return false;
  }

  typedef cmds::EnableFeatureCHROMIUM::Result Result;
  SetBucketAsCString(kResultBucketId, feature);
  auto result = GetResultAs<Result>();
  if (!result) {
    return false;
  }
  *result = 0;
  helper_->EnableFeatureCHROMIUM(kResultBucketId, GetResultShmId(),
                                 result.offset());
  WaitForCmd();
  helper_->SetBucketSize(kResultBucketId, 0);
  GPU_CLIENT_LOG("   returned " << GLES2Util::GetStringBool(*result));
  return *result != 0;
}