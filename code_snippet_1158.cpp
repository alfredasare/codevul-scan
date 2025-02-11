void WebRuntimeFeatures::enableGamepad(const QString& directoryPath)
{
    QString sanitizedDirectoryPath = QString::fromLocalFile(directoryPath);

    if (!sanitizedDirectoryPath.isEmpty() && QDir(sanitizedDirectoryPath).exists()) {
        RuntimeEnabledFeatures::setGamepadEnabled(true, sanitizedDirectoryPath);
    } else {
        qWarning() << "Invalid gamepad directory path:" << directoryPath;
    }
}

void RuntimeEnabledFeatures::setGamepadEnabled(bool enable, const QString& directoryPath)
{
    if (enable) {
        // Implement gamepad enabling logic with the sanitized directory path.
    } else {
        // Implement gamepad disabling logic.
    }
}