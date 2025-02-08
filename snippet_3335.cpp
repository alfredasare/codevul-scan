bool Downmix_foldGeneric(
 uint32_t mask, int16_t *pSrc, int16_t*pDst, size_t numFrames, bool accumulate) {

 if (!Downmix_validChannelMask(mask)) {
 return false;
 }

 const bool hasSides = (mask & kSides) != 0;
 const bool hasBacks = (mask & kBacks) != 0;

 const int numChan = audio_channel_count_from_out_mask(mask);
 const bool hasFC = ((mask & AUDIO_CHANNEL_OUT_FRONT_CENTER) == AUDIO_CHANNEL_OUT_FRONT_CENTER);
 const bool hasLFE =
 ((mask & AUDIO_CHANNEL_OUT_LOW_FREQUENCY) == AUDIO_CHANNEL_OUT_LOW_FREQUENCY);
 const bool hasBC = ((mask & AUDIO_CHANNEL_OUT_BACK_CENTER) == AUDIO_CHANNEL_OUT_BACK_CENTER);
 const int indexFC  = hasFC    ? 2 : 1; // front center
 const int indexLFE = hasLFE   ? indexFC + 1 : indexFC; // low frequency
 const int indexBL  = hasBacks ? indexLFE + 1 : indexLFE; // back left
 const int indexBR  = hasBacks ? indexBL + 1 : indexBL; // back right
 const int indexBC  = hasBC    ? indexBR + 1 : indexBR; // back center
 const int indexSL  = hasSides ? indexBC + 1 : indexBC; // side left
 const int indexSR  = hasSides ? indexSL + 1 : indexSL; // side right

 int32_t lt, rt, centersLfeContrib; // samples in Q19.12 format
 if (accumulate) {
 while (numFrames) {
            centersLfeContrib = 0;
 if (hasFC) { centersLfeContrib += pSrc[indexFC]; }
 if (hasLFE) { centersLfeContrib += pSrc[indexLFE]; }
 if (hasBC) { centersLfeContrib += pSrc[indexBC]; }
            centersLfeContrib *= MINUS_3_DB_IN_Q19_12;
            lt = (pSrc[0] << 12);
            rt = (pSrc[1] << 12);
 if (hasSides) {
                lt += pSrc[indexSL] << 12;
                rt += pSrc[indexSR] << 12;
 }
 if (hasBacks) {
                lt += pSrc[indexBL] << 12;
                rt += pSrc[indexBR] << 12;
 }
            lt += centersLfeContrib;
            rt += centersLfeContrib;
            pDst[0] = clamp16(pDst[0] + (lt >> 13));
            pDst[1] = clamp16(pDst[1] + (rt >> 13));
            pSrc += numChan;
            pDst += 2;
            numFrames--;
 }
 } else {
 while (numFrames) {
            centersLfeContrib = 0;
 if (hasFC) { centersLfeContrib += pSrc[indexFC]; }
 if (hasLFE) { centersLfeContrib += pSrc[indexLFE]; }
 if (hasBC) { centersLfeContrib += pSrc[indexBC]; }
            centersLfeContrib *= MINUS_3_DB_IN_Q19_12;
            lt = (pSrc[0] << 12);
            rt = (pSrc[1] << 12);
 if (hasSides) {
                lt += pSrc[indexSL] << 12;
                rt += pSrc[indexSR] << 12;
 }
 if (hasBacks) {
                lt += pSrc[indexBL] << 12;
                rt += pSrc[indexBR] << 12;
 }
            lt += centersLfeContrib;
            rt += centersLfeContrib;
            pDst[0] = clamp16(lt >> 13); // differs from when accumulate is true above
            pDst[1] = clamp16(rt >> 13); // differs from when accumulate is true above
            pSrc += numChan;
            pDst += 2;
            numFrames--;
 }
 }
 return true;
}
