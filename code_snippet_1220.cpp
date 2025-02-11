base::HistogramBase* GetCreatedHistogram(int index) {
  DCHECK_GT(kMaxCreateHistograms, index);
  if (created_histograms_.size() <= index) {
    created_histograms_.resize(index + 1);
  }
  return created_histograms_[index];
}