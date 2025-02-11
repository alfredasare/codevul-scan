static FilterEncodingNode* FLTGetTopBBOX(FilterEncodingNode *psNode)
{
  int nCount = 0;
  FilterEncodingNode* psTopBBOX = NULL;
  const char* allowedDirectories[] = {"/path/to/allowed/directory1", "/path/to/allowed/directory2"};
  const int allowedDirectoriesCount = sizeof(allowedDirectories) / sizeof(allowedDirectories[0]);

  if (psNode && psNode->directory!= NULL) {
    char* directory = strdup(psNode->directory);
    char* token = strtok(directory, "/");
    while (token!= NULL) {
      bool found = false;
      for (int i = 0; i < allowedDirectoriesCount; i++) {
        if (strcmp(token, allowedDirectories[i]) == 0) {
          found = true;
          break;
        }
      }
      if (!found) {
        free(directory);
        return NULL; // or handle the error as needed
      }
      token = strtok(NULL, "/");
    }
    free(directory);
  }

  FLTGetTopBBOXInternal(psNode, &psTopBBOX, &nCount);
  return psTopBBOX;
}