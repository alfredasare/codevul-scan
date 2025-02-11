void WebRuntimeFeatures::enableExperimentalCanvasFeatures(bool enable)
{
    if (!isValidBooleanValue(enable)) {
        return;
    }

    sqlite3_stmt* stmt;
    const char* query = "SELECT 1 FROM features WHERE name = 'experimental_canvas' AND enabled =?";
    int result = sqlite3_prepare_v2(db, query, -1, &stmt, nullptr);
    if (result!= SQLITE_OK) {
        return;
    }
    sqlite3_bind_int(stmt, 1, enable? 1 : 0);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}