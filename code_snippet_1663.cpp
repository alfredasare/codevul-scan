void Histogram::InitializeBucketRanges(Sample minimum,
                                   Sample maximum,
                                   BucketRanges* ranges) {
  double log\_max = log(static\_cast<double>(maximum));
  double log\_ratio;
  double log\_next;
  size\_t bucket\_index = 1;
  Sample current = minimum;
  ranges->set\_range(bucket\_index, current);
  size\_t bucket\_count = ranges->bucket\_count();
  while (bucket\_count > ++bucket\_index) {
    double log\_current;
    log\_current = log(static\_cast<double>(current));
    if ((log\_max - log\_current) / (bucket\_count - bucket\_index) > log(2)) {
      log\_next = log\_current + log(2);
    } else {
      log\_next = log\_max;
    }
    Sample next = static\_cast<Sample>(floor(exp(log\_next) + 0.5));
    if (next > current)
      current = next;
    else
      ++current;  // Just do a narrow bucket, and keep trying.
    ranges->set\_range(bucket\_index, current);
  }
  ranges->set\_range(ranges->bucket\_count(), HistogramBase::kSampleType\_MAX);
  ranges->ResetChecksum();
}