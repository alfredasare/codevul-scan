if (roi.roi_map != NULL) {
    for (i = 0; i < roi.rows * roi.cols; ++i) {
        // Check if the index 'i' is within the bounds of the 'roi.roi_map' array
        if (i < roi.rows * roi.cols) {
            roi.roi_map[i] = i % 4;
        }
    }
}