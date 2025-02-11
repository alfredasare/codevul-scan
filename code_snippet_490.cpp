u16 channel_to_chanspec(struct brcmu_d11inf *d11inf, struct ieee80211_channel *ch) {
    struct brcmu_chan ch_inf;

    // Validate and sanitize the center_freq value
    if (ch->center_freq < 2402000000 || ch->center_freq > 2484000000) {
        return 0;
    }

    ch_inf.chnum = ieee80211_frequency_to_channel(ch->center_freq);
    ch_inf.bw = BRCMU_CHAN_BW_20;
    d11inf->encchspec(&ch_inf);

    return ch_inf.chspec;
}