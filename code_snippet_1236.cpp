class AudioNode {
private:
    std::unique_ptr<HandlerType> handler_{std::make_unique<HandlerType>()};

public:
    void setChannelInterpretation(const String& interpretation,
                                 ExceptionState& exception_state) {
        handler_->SetChannelInterpretation(interpretation, exception_state);
    }
};