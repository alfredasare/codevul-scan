char line[COSINE_LINE_LENGTH + 1]; 

if (file_gets(line, COSINE_LINE_LENGTH, wth->random_fh) == NULL) {
    *err = file_error(wth->random_fh, err_info);
    if (*err == 0) {
        *err = WTAP_ERR_SHORT_READ;
    }
    line[COSINE_LINE_LENGTH] = '\0'; 
    return FALSE;
}