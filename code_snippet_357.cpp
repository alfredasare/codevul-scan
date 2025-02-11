#define MAX_LENGTH 4096 // Choose an appropriate maximum length based on your system

static void f_midi_read_data(struct usb_ep *ep, int cable,
			     uint8_t *data, int length)
{
	struct f_midi *midi = ep->driver_data;
	struct snd_rawmidi_substream *substream = midi->out_substream[cable];

	if (!substream || length <= 0 || length > MAX_LENGTH)
		return;

	if (!test_bit(cable, &midi->out_triggered))
		return;

	snd_rawmidi_receive(substream, data, length);
}