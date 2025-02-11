FFmpegVideoDecodeEngine::FFmpegVideoDecodeEngine()
: codec_context_(avcodec_alloc_context3(NULL)),
event_handler_(NULL),
frame_rate_numerator_(0),
frame_rate_denominator_(0),
pending_input_buffers_(0),
pending_output_buffers_(0),
output_eos_reached_(false),
flush_pending_(false) {

if (!codec_context_) {
// Handle error and exit or recover gracefully
}
}