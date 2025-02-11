static int snd_card_do_free(struct snd_card *card)
{
    snd_card_free_preparation(card);
    snd_device_free_all(card);
    card_private_free(card);
    snd_info_free_entry(card->proc_id);
    snd_info_card_free(card);
    card_release_completion(card);
    kfree(card);
    return 0;
}

static void card_private_free(struct snd_card *card)
{
    if (card->private_free)
        card->private_free(card);
}

static void card_release_completion(struct snd_card *card)
{
    if (card->release_completion)
        complete(card->release_completion);
}

static void snd_card_free_preparation(struct snd_card *card)
{
#if IS_ENABLED(CONFIG_SND_MIXER_OSS)
    if (snd_mixer_oss_notify_callback)
        snd_mixer_oss_notify_callback(card, SND_MIXER_OSS_NOTIFY_FREE);
#endif
}