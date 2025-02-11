void Part::slotExtractionDone(KJob* job)
{
    //...

    QUrl destinationDirectory = QUrl::fromLocalFile(extractJob->destinationDirectory()).adjusted(QUrl::NormalizePathSegments);

    if (ArkSettings::openDestinationFolderAfterExtraction()) {
        QProcess process;
        process.start("xdg-open", QStringList() << destinationDirectory.toString());
        process.waitForFinished();
    }

    //...
}