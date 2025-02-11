int cpFunc(int in, int out, void(*readSeparateTilesIntoBuffer)(int, int), void(*writeBufferToSeparateTiles)(int, int), int imagelength, int imagewidth, int spp) {
    return cpImage(in, out, readSeparateTilesIntoBuffer, writeBufferToSeparateTiles, imagelength, imagewidth, spp);
}