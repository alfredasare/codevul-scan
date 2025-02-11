AviaryScheddPlugin::processDirtyJobs()
{
    BeginTransaction();

    while (!dirtyJobs->empty()) {
        DirtyJobEntry entry = dirtyJobs->front(); dirtyJobs->pop_front();
        string key = entry.first;
        string name = entry.second.first;

        // Validate 'name' parameter
        const string allowedChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-.";
        for (char c : name) {
            if (allowedChars.find(c) == string::npos) {
                // Reject input with disallowed characters
                continue;
            }
        }

        string safeName = "";
        for (char c : name) {
            if (allowedChars.find(c)!= string::npos) {
                safeName += c;
            }
        }
        name = safeName;

        int value = entry.second.second;
        processJob(key.c_str(), name.c_str(), value);
    }

    CommitTransaction();

    isHandlerRegistered = false;
}