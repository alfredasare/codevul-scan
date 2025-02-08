FaxModem::initializeDecoder(const Class2Params& params)
{
    setupDecoder(recvFillOrder, params.is2D(), (params.df == DF_2DMMR));

    u_int rowpixels = params.pageWidth();	// NB: assume rowpixels <= 4864
    tiff_runlen_t runs[2*4864];			// run arrays for cur+ref rows
    setRuns(runs, runs+4864, rowpixels);
    setIsECM(false);
    resetLineCounts();
}
