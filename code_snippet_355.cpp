QString Part::sanitizePath(const QString& path) const
{
    QRegExp sanitizedPathPattern("^[a-zA-Z0-9\\-_\\.]+$");
    if (sanitizedPathPattern.exactMatch(path)) {
        return path;
    } else {
        return {};
    }
}