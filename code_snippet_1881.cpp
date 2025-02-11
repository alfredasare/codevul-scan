static void AppLayerProtoDetectFreeProbingParsers(AppLayerProtoDetectProbingParser *pp)
{
    SCEnter();

    if (pp == NULL) {
        SCReturn; // or handle the error appropriately
    }

    while (pp!= NULL) {
        if (pp->next == NULL) {
            break; // exit the loop when pp->next is NULL
        }
        AppLayerProtoDetectProbingParserFree(pp);
        pp = pp->next;
    }

 end:
    SCReturn;
}