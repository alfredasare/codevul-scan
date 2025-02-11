void AudioInputRendererHost::DeleteEntries() {
  DCHECK(BrowserThread::CurrentlyOn(BrowserThread::IO));

  // Create a copy of the keys before iterating.
  AudioEntryMap audio_entries_copy = audio_entries_;

  for (AudioEntryMap::iterator i = audio_entries_copy.begin();
       i != audio_entries_copy.end(); ++i) {
    CloseAndDeleteStream(i->second);
  }

  audio_entries_.clear();
}