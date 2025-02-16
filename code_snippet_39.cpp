cmsBool WriteOneMLUC(struct _cms_typehandler_struct* self, cmsIOHANDLER* io, _cmsDICelem* e, cmsUInt32Number i, const cmsMLU* mlu, cmsUInt32Number BaseOffset, cmsUInt32Number BufferSize)
{
    cmsUInt32Number Before;

    if (mlu == NULL) {
        e ->Sizes[i] = 0;
        e ->Offsets[i] = 0;
        return TRUE;
    }

    Before = io ->Tell(io);
    e ->Offsets[i] = Before - BaseOffset;

    if (!Type_MLU_Write(self, io, (void*) mlu, 1)) return FALSE;

    e ->Sizes[i] = io ->Tell(io) - Before;

    // Check if the calculated size is within the buffer limit
    if (e ->Sizes[i] >= BufferSize) {
        return FALSE; // Or handle the error as per the application requirement
    }

    return TRUE;
}