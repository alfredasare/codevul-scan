static void ttusbdecfe_release(struct dvb_frontend* fe)
{
	struct ttusbdecfe_state* state = (struct ttusbdecfe_state*) fe->demodulator_priv;

	if (state && state->initialized) {
		state->initialized = 0;
		kfree(state);
	}
}