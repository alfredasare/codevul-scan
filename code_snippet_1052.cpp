std::unique_ptr<Handler> handler;
void AudioNode::setChannelInterpretation(const String& interpretation, ExceptionState& exception_state) {
  handler.reset(new Handler());
  handler->SetChannelInterpretation(interpretation, exception_state);
}