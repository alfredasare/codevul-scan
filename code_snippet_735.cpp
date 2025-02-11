SafeSock::peek_end_of_message()
{
	if(_msgReady) {
		if(_longMsg) { // long message is ready
			if(_longMsg->consumed()) {
				_msgReady = _longMsg = nullptr;
				return true;
			}
		} else { // short message is ready
			if(_shortMsg.consumed()) {
				_msgReady = nullptr;
				return true;
			}
		}
	}
	return false;
}