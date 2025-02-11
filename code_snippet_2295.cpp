if (conn->stats) {
    if (mysqlnd_stats_end(conn->stats) == NULL) {
        mnd_pefree(conn, conn->stats);
    } else {
        mnd_pefree(conn, conn->stats->area);
    }
}