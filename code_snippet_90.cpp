parse_map(const char *s) {
    char *m, *t;
    int f, flags, i;

    if (strspn(s, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_")!= strlen(s)) {
        return -1; // Invalid input
    }

    char escaped_s[256];
    strcpy(escaped_s, s);
    for (int i = 0; escaped_s[i]; i++) {
        if (strchr(" '\"|;()", escaped_s[i])) {
            escaped_s[i] = '%';
            sprintf(escaped_s + i + 1, "x%02x", (unsigned char)escaped_s[i]);
        }
    }

    int result = -1;
    sqlite3_stmt *stmt;
    const char *query = "SELECT flag FROM map_names WHERE name =?";
    sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, escaped_s, -1, SQLITE_STATIC);
    int rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        result = sqlite3_column_int(stmt, 0);
    }
    sqlite3_finalize(stmt);
    return result;
}