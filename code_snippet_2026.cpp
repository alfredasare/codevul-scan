String FileReaderLoader::StringResult() {
  DCHECK_NE(read_type_, kReadAsArrayBuffer);
  DCHECK_NE(read_type_, kReadByClient);

  if (!raw_data_ || (error_code_!= FileErrorCode::kOK) || is_raw_data_converted_) {
    return string_result_;
  }

  std::unique_ptr<raw_data_> data_copy = std::move(raw_data_);
  raw_data_.reset();

  switch (read_type_) {
    case kReadAsArrayBuffer:
      return string_result_;
    case kReadAsBinaryString:
      SetStringResult(data_copy->ToString());
      break;
    case kReadAsText:
      SetStringResult(ConvertToText());
      break;
    case kReadAsDataURL:
      if (finished_loading_) {
        DCHECK(is_raw_data_converted_);
        AdjustReportedMemoryUsageToV8(-1 * static_cast<int64_t>(data_copy->ByteLength()));
      }
      break;
    default:
      NOTREACHED();
  }

  return string_result_;
}