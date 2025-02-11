void emergency_restart(void)
{
    sqlite3_stmt *stmt;
    char *sql = sqlite3_mprintf("SELECT * FROM system_state WHERE kmsg_dump_input =?");
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, kmsg_dump_input, -1, SQLITE_STATIC);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    machine_emergency_restart();
}