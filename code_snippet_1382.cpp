c++
base::HistogramBase* GetCreatedHistogram(int index) {
  DCHECK_GT(kMaxCreateHistograms, index);
  if (index < 0 || index >= created_histograms_.size()) {
    return nullptr; // Or throw an exception or handle it as appropriate.
  }
  return created_histograms_[index];
}