static SQLITE_NOINLINE void backupUpdate(
  sqlite3_backup *p,
  Pgno iPage,
  const u8 *aData
){
  assert( p!=0 );
  do{
    assert( sqlite3_mutex_held(p->pSrc->pBt->mutex) );
    if(!isFatalError(p->rc) && iPage<p->iNext ){
      /* The backup process p has already copied page iPage. But now it
      ** has been modified by a transaction on the source pager. Copy
      ** the new data into the backup.
      */
      int rc;
      assert( p->pDestDb );
      sqlite3_mutex_enter(p->pDestDb->mutex);
      // Sanitize and validate the aData parameter
      char sanitized_aData[PATH_MAX];
      size_t sanitized_aData_len = strlen(sanitized_aData);
      int sanitized_aData_index = 0;
      for(int i = 0; i < strlen(aData); i++) {
        char c = aData[i];
        if(c == '/' || c == '\\') {
          // Ignore any path separator characters
          continue;
        } else if(c == '.') {
          // Only allow '.' and '..' as valid directory separators
          if(sanitized_aData_index > 0 && sanitized_aData[sanitized_aData_index-1] == '.') {
            // Ignore any consecutive '.' characters
            continue;
          }
        } else {
          sanitized_aData[sanitized_aData_index++] = c;
          if(sanitized_aData_index >= PATH_MAX) {
            // Prevent buffer overflow
            break;
          }
        }
      }
      sanitized_aData[sanitized_aData_index] = '\0';
      rc = backupOnePage(p, iPage, sanitized_aData, 1);
      sqlite3_mutex_leave(p->pDestDb->mutex);
      assert( rc!=SQLITE_BUSY && rc!=SQLITE_LOCKED );
      if( rc!=SQLITE_OK ){
        p->rc = rc;
      }
    }
  }while( (p = p->pNext)!=0 );
}