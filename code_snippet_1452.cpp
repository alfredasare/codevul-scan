void DocumentModuleScriptFetcher::Finalize(
const WTF::Optional<ModuleScriptCreationParams>& params,
const HeapVector<Member<ConsoleMessage>>& error\_messages) {
if (params.hasValue()) {
NotifyFetchFinished(params.value(), error\_messages);
}
}