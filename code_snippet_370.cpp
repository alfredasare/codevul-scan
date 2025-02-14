void snd_msndmidi_input_read(void *mpuv)
{
	unsigned long flags;
	struct snd_msndmidi *mpu = mpuv;
	void *pwMIDQData = mpu->dev->mappedbase + MIDQ_DATA_BUFF;

	spin_lock_irqsave(&mpu->input_lock, flags);
	while (readw(mpu->dev->MIDQ + JQS_wTail) !=
	       readw(mpu->dev->MIDQ + JQS_wHead)) {
		u16 wTmp, val;
			if (readw(mpu->dev->MIDQ + JQS_wHead) + 1 >
			    readw(mpu->dev->MIDQ + JQS_wSize)) {
				writew(0, mpu->dev->MIDQ + JQS_wHead);
				wTmp = 0;
			} else {
				wTmp = readw(mpu->dev->MIDQ + JQS_wHead) + 1;
			}
			val = readw(pwMIDQData + 2 * wTmp);
			if (test_bit(MSNDMIDI_MODE_BIT_INPUT_TRIGGER,
				     &mpu->mode))
				snd_rawmidi_receive(mpu->substream_input,
						    (unsigned char *)&val, 1);
		writew(wTmp, mpu->dev->MIDQ + JQS_wHead);
	}
	spin_unlock_irqrestore(&mpu->input_lock, flags);
}