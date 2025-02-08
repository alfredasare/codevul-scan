SafeSock::peek_end_of_message()
{
	if(_msgReady) {
		if(_longMsg) { // long message is ready
			if(_longMsg->consumed()) {
				return true;
			}
		} else { // short message is ready
			if(_shortMsg.consumed())
				return true;
		}
	}
	return false;
}
