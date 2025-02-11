class RgnIterPair {
public:
    RgnIterPair(const SkRegion& rgn, int max_iterators = 10)
        : fRgn(rgn), fMaxIterators(max_iterators), fIteratorCount(0) {}

    void resetIterator() {
        if (fIteratorCount < fMaxIterators) {
            fIter.reset(fRgn);
            fIteratorCount++;
        } else {
            // Throw an exception or log an error here
        }
    }

private:
    const SkRegion& fRgn;
    SkRegion::Iter fIter;