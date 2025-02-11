WebLocalFrameImpl::ExecuteScriptInIsolatedWorldAndReturnValue(
int world_id,
const WebScriptSource& source_in) {
BETTER_DCHECK(GetFrame());
BETTER_CHECK_GT(world_id, 0);
BETTER_CHECK_LT(world_id, DOMWrapperWorld::kEmbedderWorldIdLimit);

return GetFrame()->GetScriptController().ExecuteScriptInIsolatedWorld(
world_id, source_in);
}

// Add the new BETTER_DCHECK and BETTER_CHECK_ functions

#ifndef NDEBUG
void BETTER_DCHECK(bool condition) {
#if defined(DCHECK_IS_ON)
  if (!condition)
    DLOG(FATAL) << "DCHECK FAILED: " << __FILE__ << ":" << __LINE__;
#endif  // defined(DCHECK_IS_ON)
}

template <typename T>
T BETTER_DCHECK_OP(T value, bool condition) {
#if defined(DCHECK_IS_ON)
  if (!condition)
    DLOG(FATAL) << "DCHECK FAILED: " << __FILE__ << ":" << __LINE__;
#endif  // defined(DCHECK_IS_ON)
  return value;
}

template <typename T>
T BETTER_DCHECK_GE(T value, T limit) {
#if defined(DCHECK_IS_ON)
  if (value < limit)
    DLOG(FATAL) << "DCHECK FAILED: " << __FILE__ << ":" << __LINE__;
#endif  // defined(DCHECK_IS_ON)
  return value;
}

template <typename T>
T BETTER_DCHECK_LE(T value, T limit) {
#if defined(DCHECK_IS_ON)
  if (value > limit)
    DLOG(FATAL) << "DCHECK FAILED: " << __FILE__ << ":" << __LINE__;
#endif  // defined(DCHECK_IS_ON)
}

template <typename T>
T BETTER_CHECK_GT(T value, T limit) {
#if defined(DCHECK_IS_ON) || defined(ADDRESS_SANITIZER)
  if (value <= limit)
    DLOG(FATAL) << "CHECK FAILED: " << __FILE__ << ":" << __LINE__;
#endif  // defined(DCHECK_IS_ON) || defined(ADDRESS_SANITIZER)
  return value;
}

template <typename T>
T BETTER_CHECK_LT(T value, T limit) {
#if defined(DCHECK_IS_ON) || defined(ADDRESS_SANITIZER)
  if (value >= limit)
    DLOG(FATAL) << "CHECK FAILED: " << __FILE__ << ":" << __LINE__;
#endif  // defined(DCHECK_IS_ON) || defined(ADDRESS_SANITIZER)
  return value;
}
#endif  // NDEBUG