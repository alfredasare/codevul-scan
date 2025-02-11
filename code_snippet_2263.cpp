code:

static int usb_audio_suspend(struct usb_interface *intf, pm_message_t message)
{
    struct snd_usb_audio *chip = usb_get_intfdata(intf);
    if (chip != NULL) {
        chip->autosuspended = !!PMSG_IS_AUTO(message);
        if (!chip->autosuspended)
            snd_power_change_state(chip->card, SNDRV_CTL_POWER_D3hot);
        if (!chip->num_suspended_intf++) {
            list_for_each_entry(as, &chip->pcm_list, list) {
                snd_pcm_suspend_all(as->pcm);
                as->substream[0].need_setup_ep = as->substream[1].need_setup_ep = true;
            }
            list_for_each(p, &chip->midi_list)
                snd_usbmidi_suspend(p);
            list_for_each_entry(mixer, &chip->mixer_list, list)
                snd_usb_mixer_suspend(mixer);
        }
    } else {
        printk(KERN_ERR "usb_audio_suspend: chip is null\n");
        return -EINVAL;
    }
    return 0;
}