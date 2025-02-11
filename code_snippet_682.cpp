void testUriUserInfoHostPort5() {
    UriParserStateA stateA;
    UriUriA uriA;
    memset(&uriA, 0, sizeof(UriUriA));  // Initialize uriA structure
    stateA.uri = &uriA;
    const char * const input = "http" "://" "localhost";
    TEST_ASSERT(0 == uriParseUriA(&stateA, input));
    TEST_ASSERT(uriA.userInfo.first == NULL);
    TEST_ASSERT(uriA.userInfo.afterLast == NULL);
    TEST_ASSERT(uriA.hostText.first == input + 4 + 3);
    TEST_ASSERT(uriA.hostText.afterLast == input + 4 + 3 + 9);
    TEST_ASSERT(uriA.portText.first == NULL);
    TEST_ASSERT(uriA.portText.afterLast == NULL);
    uriFreeUriMembersA(&uriA);
}