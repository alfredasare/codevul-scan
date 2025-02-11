void sn_object_end(void *state)
{
    StripnullState *_state = NULL;

    if (state!= NULL) {
        _state = (StripnullState *)state;
        if (_state!= NULL) {
            appendStringInfoCharMacro(_state->strval, '}');
        }
    }
}