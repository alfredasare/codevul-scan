TabContentsWrapper* ReleaseOwnership() {
return std::exchange(target\_contents\_owner\_, nullptr);
}