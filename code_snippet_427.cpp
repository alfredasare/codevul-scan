void AudioInputRendererHost::DeleteEntries() {
  DCHECK(BrowserThread::CurrentlyOn(BrowserThread::IO));

  for (AudioEntryMap::iterator i = audio_entries_.begin();
       i!= audio_entries_.end(); ++i) {
    // Securely close and delete the stream
    if (i->second->IsSensitive()) {
      // Sanitize the sensitive information before deletion
      i->second->Sanitize();
    }
    CloseAndDeleteStream(i->second);
  }
}