Project_x( EXEC_OP_ FT_Pos  dx,
           FT_Pos  dy )
{
    if (!isValidInput(dx)) {
        return -1;
    }

    dx = sanitizeInput(dx);
    FT_UNUSED_EXEC = 0;
    return dx;
}

bool isValidInput(FT_Pos dx) {
    const char* allowedChars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int length = strlen(dx);
    for(int i = 0; i < length; i++) {
        if(strchr(allowedChars, dx[i]) == NULL) {
            return false;
        }
    }
    return true;
}

FT_Pos sanitizeInput(FT_Pos dx) {
    char sanitized[100]; // assuming a maximum length of 100
    int j = 0;
    for(int i = 0; i < strlen(dx); i++) {
        if(dx[i]!= '/' && dx[i]!= '\\' && dx[i]!= '.' && dx[i]!= '..') {
            sanitized[j++] = dx[i];
        }
    }
    sanitized[j] = '\0';
    return atoi(sanitized);
}