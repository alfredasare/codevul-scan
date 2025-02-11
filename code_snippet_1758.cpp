c++
void MyOggExtractor::buildTableOfContents() {
    off64_t offset = mFirstDataOffset;
    Page page;
    ssize_t pageSize;
    while ((pageSize = readPage(&page)) > 0) {
        mTableOfContents.push();
        TOCEntry &entry = mTableOfContents.editItemAt(mTableOfContents.size() - 1);
        entry.mPageOffset = offset;
        entry.mTimeUs = getTimeUsOfGranule(page.mGranulePosition);
        offset += pageSize;
    }
}