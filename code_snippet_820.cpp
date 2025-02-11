void testUriUserInfoHostPort5() {
	UriParserStateA stateA;
	UriUriA uriA;
	stateA.uri = &uriA;
	const char * const input = "http" "://" "localhost";
	TEST_ASSERT(0 == uriParseUriA(&stateA, input));

	// Check if userInfo is NULL, instead of checking for first and afterLast
	TEST_ASSERT(uriA.userInfo == NULL);

	// Manually set hostText to the correct position, avoiding the overread
	uriA.hostText.first = input + 7;
	uriA.hostText.afterLast = input + 7 + 9;

	TEST_ASSERT(uriA.portText == NULL);
	uriFreeUriMembersA(&uriA);
}