static void AppLayerProtoDetectFreeProbingParsers(AppLayerProtoDetectProbingParser *pp)
{
    SCEnter();

    if (pp == NULL)
        goto end;

    AppLayerProtoDetectProbingParser *tmp_pp = NULL;
    while (pp != NULL) {
        tmp_pp = pp->next;
        AppLayerProtoDetectProbingParserFree(pp);
        pp = tmp_pp;
    }

 end:
    SCReturn;
}