static int esil_6502_fini(RAnalEsil *esil) {
    if (esil == NULL || esil->size <= 0) {
        return false; // or throw an error
    }
    // Now we can safely access esil's members
    return true;
}