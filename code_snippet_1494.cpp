void Histogram::InitializeBucketRanges(Sample minimum,
                                       Sample maximum,
                                       BucketRanges* ranges) {
  double log_max = log(static_cast<double>(maximum));
  double log_ratio;
  double log_next;
  size_t bucket_index = 1;
  Sample current = minimum;
  ranges->set_range(bucket_index, current);
  size_t bucket_count = ranges->bucket_count();
  while (bucket_count > ++bucket_index) {
    double log_current;
    log_current = log(static_cast<double>(current));
    log_ratio = (log_max - log_current) / (bucket_count - bucket_index);
    log_next = log_current + log_ratio;
    long long next_val = llround(exp(log_next) + 0.5);
    if (next_val > LLONG_MAX || next_val < LLONG_MIN) {
      // Handle the case where the result exceeds the range of long long
      // For example, you can raise an error or clamp the value
    } else {
      Sample next = static_cast<Sample>(next_val);
      if (next > current)
        current = next;
      else
        ++current;  // Just do a narrow bucket, and keep trying.
    }
    ranges->set_range(bucket_index, current);
  }
  ranges->set_range(ranges->bucket_count(), HistogramBase::kSampleType_MAX);
  ranges->ResetChecksum();
}